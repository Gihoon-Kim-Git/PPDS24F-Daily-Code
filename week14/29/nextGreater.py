"""
<Next Greater Element>
"""

def next_greater_element(nums1, nums2):
    # Create a dictionary to store the next greater element for each number in nums2
    next_greater = {}
    stack = []
    
    # Traverse nums2 to calculate the next greater element for each number
    for num in nums2:
        # Maintain the stack in decreasing order
        while stack and stack[-1] < num:
            next_greater[stack.pop()] = num
        stack.append(num)
    
    # For remaining elements in the stack, there is no next greater element
    while stack:
        next_greater[stack.pop()] = -1
    
    # Prepare the result for nums1 using the next_greater dictionary
    return [next_greater[num] for num in nums1]

nums1 = [4, 1, 2]
nums2 = [1, 3, 4, 2]
result = next_greater_element(nums1, nums2)
print(result)  # Output: [-1, 3, -1]

nums1 = [2, 4]
nums2 = [1, 2, 3, 4]
result = next_greater_element(nums1, nums2)
print(result)  # Output: [3, -1]

