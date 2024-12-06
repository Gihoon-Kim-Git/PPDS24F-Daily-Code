# test = [3,2,1]
# test=sorted(test)
# print(test)
# test1=test.sort()
# print(test1)

# test1 = [5,1,2,6]
# # test2 = test1.reverse()
# # print(test2)
# test1.reverse()
# # print(test1)

# # print(test1.index(min(test1)))
# # print(test1[:4])
# # print(test1[:3])
# # print(test1[:3]+[test1[3]])
# # print(test1[3:])
# # print([1,2]+test1[10:])

# arr = [5,1,2,6,7,0]
# n=3

# idx = arr[:n].index(max(arr[:n]))
# print("idx=",idx)
# temp = arr[:idx+1].reverse()
# print("temp=",temp)
# arr = temp + arr[idx+1:]
# print("arr=",arr)
# arr = arr.reverse()
# print("arr=",arr)

from typing import List

class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        ans = []
        arr2 = sorted(arr)
        n = len(arr)
        while arr!=arr2 :
            if arr[:n].index(max(arr[:n])) == n-1 :
                n -= 1
                arr = arr[:n]
                arr2 = sorted(arr)
                continue
            else:
                idx = arr[:n].index(max(arr[:n]))
                ans.append(idx+1)
                temp = arr[:idx+1]
                temp.reverse()
                arr = temp + arr[idx+1:]
                ans.append(n)
                arr.reverse()
                n -= 1
                arr = arr[:n]
                arr2 = sorted(arr)
        return ans


"""
class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        res=[]
        for i in range(len(arr)-1,-1,-1):
            if arr[i]!=i+1:
                for j in range(i-1,-1,-1):
                    if arr[j]==i+1:
                        break
                arr[:j+1]=arr[:j+1][::-1]
                arr[:i+1]=arr[:i+1][::-1]
                res.append(j+1)
                res.append(i+1)
        return res
"""

"""
class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        ans = []
        n = len(arr)
        
        while n > 1:
            # 현재 배열에서 최대값의 인덱스 찾기
            max_idx = arr.index(max(arr[:n]))
            
            # 최대값이 이미 올바른 위치에 있는 경우
            if max_idx == n - 1:
                n -= 1
                continue
            
            # 최대값을 배열 맨 앞으로 이동
            if max_idx != 0:
                ans.append(max_idx + 1)
                arr[:max_idx + 1] = reversed(arr[:max_idx + 1])
            
            # 최대값을 배열 맨 뒤로 이동
            ans.append(n)
            arr[:n] = reversed(arr[:n])
            
            # 유효한 범위를 줄임
            n -= 1
        
        return ans
"""