""""The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above."""

"""Constraints:
    1 <= nums1.length <= nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 104
    All integers in nums1 and nums2 are unique.
    All the integers of nums1 also appear in nums2."""
    
"""아이디어
    nums2에서 nums1[i]와 같은 숫자를 찾을 때에, nums1[-1]에서부터 거꾸로 내려오면서 찾음.
이때 찾으면서, nums1[i]보다 큰 요소라면 upadte(어차피 nums1[i]와 같은 값인 nums2[j]와 가장 위치적으로 가까운 요소가 first greater element이니까.) 
        만약 거꾸로 내려오면서 찾았는데 nums1[i]보다 큰 요소는 못 찾았는데 nums1[i]인 nums2[j]에 도달하면, -1로 값 저장.
"""

"""수도코드
목표 : nums1[i]와 일치하는 nums2[j]보다 오른쪽에 있는 수 중 first greater element를 찾아서 answer에 append.

1. nums1과 동일한 크기의 answer_list 초기화 (모든 값 -1)

2. nums1에 대한 for문 돌면서 차례대로 값 찾기 (i)
    target = nums1[i]
    greater = -1
    nums2에 대한 for문을 마지막 요소로부터 왼쪽으로 순회하면서 돌기. (j)
        만약 nums2[j]가 target보다 크면 :
            greater = nums2[j]
        elif nums2[j] == target :
            answer_list[i] = greater
            break

3. 결과 반환 : return answer_list
"""
#%%
class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        answer_list = [ -1 for _ in range(len(nums1))]
        greater = -1
        
        for i in range(len(nums1)):
            target = nums1[i]
            greater = -1
            for j in range(len(nums2)-1, -1, -1):
                if nums2[j] > target:
                    greater = nums2[j]
                elif nums2[j] == target :
                    answer_list[i] = greater
                    break
                
        return answer_list
        

sol1 = Solution()
# nums1 = [4,1,2]
# nums2 = [1,3,4,2]
nums1 = [2,4]
nums2 = [1,2,3,4]
print(sol1.nextGreaterElement(nums1, nums2))
#%%
#[Stack, Dictionary를 이용한 풀이1] ----------------------------------------------------------

def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
	if not nums2:
		return None

	mapping = {}
	result = []
	stack = []
	stack.append(nums2[0])

	for i in range(1, len(nums2)):
		while stack and nums2[i] > stack[-1]:       # if stack is not empty, then compare it's last element with nums2[i]
			mapping[stack[-1]] = nums2[i]           # if the new element is greater than stack's top element, then add this to dictionary 
			stack.pop()                             # since we found a pair for the top element, remove it.
		stack.append(nums2[i])                      # add the element nums2[i] to the stack because we need to find a number greater than this

	for element in stack:                           # if there are elements in the stack for which we didn't find a greater number, map them to -1
		mapping[element] = -1

	for i in range(len(nums1)):
		result.append(mapping[nums1[i]])
	return result

#[Stack, Dictionary를 이용한 풀이2] ----------------------------------------------------------

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        hashMap = {} # 각 요소의 다음에 오는 더 큰 요소를 저장
        stack = [] # 아직 다음 큰 요소를 찾지 못한 요소들을 임시로 저장.

        for num in nums2: #nums2를 순회하면서 hashMap 작성
            while stack and stack[-1] <  num: # "현재 요소"가 스택의 마지막 요소보다 크면, HashMap[스택의 마지막 요소] = "현재 요소" (스택의 마지막 요소의 first greater element)
                hashMap[stack.pop()] = num
            stack.append(num)
        return [hashMap.get(i,-1) for i in nums1] # hashMap.get(key, default) :딕셔너리에서 key에 해당하는 값을 찾아 반환하되, 만약 key가 딕셔너리에 존재하지 않는다면, 주어진 default 값을 반환

# %%
