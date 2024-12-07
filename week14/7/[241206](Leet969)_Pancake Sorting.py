"""Given an array of integers arr, sort the array by performing a series of pancake flips.

In one pancake flip we do the following steps:

Choose an integer k where 1 <= k <= arr.length.
Reverse the sub-array arr[0...k-1] (0-indexed).
For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.

Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.

 """
 
"""Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= arr.length
All integers in arr are unique (i.e. arr is a permutation of the integers from 1 to arr.length)."""

"""아이디어
목표 : reverse로만 sort되도록 만들기 위해서 뒤집어야하는 subarray 개수를 차례대로 넣은 리스트 반환 (총 뒤집는 과정의 횟수가 10*array 길이 이내일 수 있게.)
    
이건 무슨 방법으로 푸는 문제일까!
Level1 : array를 2 ~ len(array)까지 바꿨을 때 결과
Level2 : Level1의 결과에서, 현재 결과를 만든 k를 제외하고  2 ~ len(array)까지 적용한 결과
Lelvel3: ....  Level2의 결과에 대해,  현재 결과를 만든 k를 제외하고  2 ~ len(array)까지 적용한 결과

2~len(array)를 permutation해서 순서대로 만들고
해당 순서대로 직접 sort해보는 것만이 방법일 거 같은데.?
"""


#%%

"""수도코드
목표 : reverse로만 sort되도록 만들기 위해서 뒤집어야하는 subarray 개수를 차례대로 넣은 리스트 반환 (총 뒤집는 과정의 횟수가 10*array 길이 이내일 수 있게.)

1. 만약 arr가 이미 sort되어 있다면 빈 리스트 반환

2. 2 ~ len(array)만큼의 가능한 모든 permutation (중복 허용)을 저장. (최대 길이는 10*len(arr))

3. permutations를 처음부터 순회하면서 arr_temp가 arr_sorted랑 같아지는 순간 break
"""


#%% [최종제출] 시간안에 되는 풀이 : 뒤에서부터 정렬시키기
class Solution(object):
    def pancakeSort(self, arr):
        answer = []
        for target in range(len(arr), 0, -1):
            max_idx = arr.index(target)
            if max_idx != target - 1:
                if max_idx != 0:
                    answer.append(max_idx + 1)
                    arr[:max_idx + 1] = arr[:max_idx + 1][::-1]
                answer.append(target)
                arr[:target] = arr[:target][::-1]
        return answer

#%% 풀이 1 : 155/215 cases passed. memory limit exceede : [10,5,1,6,3,8,2,4,7,9] 이런 경우에.

#바로 앞의 요소와 중복되지 않도록!
def generate_subsets(lst_in, max_len):
    result = []
    
    def dfs(current_subset: list[int]):
        if len(current_subset) > 0:
            result.append(current_subset[:])  # 현재 부분집합을 결과에 추가
        
        if len(current_subset) < max_len:  # 최대 길이를 넘지 않는 경우에만 재귀적으로 요소 추가
            last_element = current_subset[-1] if current_subset else None
            for e in lst_in:
                if e != last_element:  # 직전 요소와 다른 경우에만 추가
                    current_subset.append(e)
                    dfs(current_subset)
                    current_subset.pop()
    
    dfs([])
    return result


class Solution(object):
    def pancakeSort(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        
        arr_sorted = arr[:]
        arr_sorted.sort()
        
        if arr == arr_sorted : 
            return []
        
        # 2 ~ len(array)의 순서permutation을 만들자. (순서permutation의 길이는 1 ~ 10*len(array)) 
        elements = [ i for i in range(2, len(arr)+1)]
        max_len =  len(arr)
        permutations = generate_subsets(elements, max_len)
        
        #3. permutations를 처음부터 순회하면서 arr_temp가 arr_sorted랑 같아지는 순간 break
        answer = []
        for i in range(len(permutations)):
            arr_temp = arr[:]
            cur_perm = permutations[i] #ex.[4,2,4,3]
            cur_index = 0
            find_answer = 0
            while cur_index < len(cur_perm) :
                arr_temp_sub = arr_temp[:cur_perm[cur_index]]
                arr_temp_left = arr_temp[cur_perm[cur_index]:]
                arr_temp = arr_temp_sub[::-1] + arr_temp_left
                if arr_temp == arr_sorted :
                    find_answer = 1
                    break
                cur_index += 1
            if find_answer == 1 :
                answer = cur_perm[:cur_index+1]
                break
                
        return answer        
                
                
sol1 = Solution()
arr = [3,2,4,1]
print(sol1.pancakeSort(arr))        

        
        
        
        
# %%
# 풀이 핵심 : array의 뒷자리부터 자기 위치에 맞도록 정렬해주어야 함! 뒤에는 한 번 자리를 잡으면 제외할 수 있음.