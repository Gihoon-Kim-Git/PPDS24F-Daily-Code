from typing import List
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        n = len(nums2)
        for x in nums1:
            idx = nums2.index(x)
            cond = False
            for y in range(idx+1,n):
                if nums2[y] > x :
                    ans.append(nums2[y])
                    cond = True
                    break
            if not cond : ans.append(-1)
        
        return ans
    
# class Solution:
#     def nextGreaterElement(self, nums1, nums2):
#         stack = []
#         hashmap = {}

#         for num in nums2:
#             while stack and num > stack[-1]:
#                 hashmap[stack.pop()] = num
#             stack.append(num)

#         # while stack:
#         #     hashmap[stack.pop()] = -1

#         return [hashmap.get(i, -1) for i in nums1] #-1 is default value if the key i isn't present in the hashmap