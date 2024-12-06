class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = []
        greater_map = {}
        
        for num in nums2:
            while stack and stack[-1] < num:
                greater_map[stack.pop()] = num
            stack.append(num)
        
        while stack:
            greater_map[stack.pop()] = -1
        
        ans = [greater_map[num] for num in nums1]
        return ans
