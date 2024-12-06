class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # Dictionary to store the next greater element for each number in nums2
        next_greater = {}
        stack = []

        # Traverse nums2 to build the next_greater mapping
        for num in nums2:
            # Maintain a decreasing stack; if the current number is greater than the top of the stack,
            # it means it is the next greater element for the number at the top of the stack
            while stack and stack[-1] < num:
                smaller = stack.pop()
                next_greater[smaller] = num
            # Push the current number onto the stack
            stack.append(num)
        
        # For any remaining elements in the stack, there is no next greater element
        while stack:
            next_greater[stack.pop()] = -1
        
        # Generate the result for nums1 using the mapping
        return [next_greater[num] for num in nums1]
