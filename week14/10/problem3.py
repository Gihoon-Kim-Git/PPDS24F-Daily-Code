from collections import List 

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        next_greater = {}
        stack = []

        for num in reversed(nums2):
            while stack and stack[-1] <= num:
                stack.pop()
            next_greater[num] = stack[-1] if stack else -1
            stack.append(num)

        result = [next_greater[num] for num in nums1]
        return result