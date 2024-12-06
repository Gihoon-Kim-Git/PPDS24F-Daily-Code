def next_greater_element(nums1, nums2):
    """
    Find the next greater element for each element in nums1 as a subset of nums2.
    """
    # Dictionary to store the next greater element for each number in nums2
    next_greater = {}
    # Monotonic stack to keep track of elements for which we haven't found the next greater
    stack = []

    # Iterate through nums2 to compute the next greater element for each
    for num in nums2:
        # While the stack is not empty and the current number is greater than the top of the stack
        while stack and num > stack[-1]:
            next_greater[stack.pop()] = num
        # Push the current number onto the stack
        stack.append(num)
    
    # Remaining elements in the stack have no next greater element
    for num in stack:
        next_greater[num] = -1

    # Use the dictionary to find the results for nums1
    return [next_greater[num] for num in nums1]

# Example usage:
nums1 = [4, 1, 2]
nums2 = [1, 3, 4, 2]
result = next_greater_element(nums1, nums2)
result
