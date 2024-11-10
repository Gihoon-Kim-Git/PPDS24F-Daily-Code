# Suppose an array of length n is sorted in ascending order and then rotated
# between 1 and n times. We need to find the minimum element in this array.

# Example of a rotated sorted array:
# Original sorted array: [0, 1, 4, 4, 5, 6, 7]
# After 4 rotations: [4, 5, 6, 7, 0, 1, 4]
# After 7 rotations (or no rotation): [0, 1, 4, 4, 5, 6, 7]

# Note: Rotating an array [a[0], a[1], ..., a[n-1]] one time results in
# [a[n-1], a[0], a[1], ..., a[n-2]].

# Given the sorted and rotated array `nums` which may contain duplicates,
# our goal is to return the minimum element in this array.

# We aim to reduce the overall operation steps as much as possible, ideally
# using a binary search approach to achieve O(log n) time complexity.

def findMin(nums):
    # initialization: pointers to start and end of array
    left = 0
    right = len(nums) - 1
    
    # Binary Search approach: reduce the time complexity O(log n)
    # adjust pointers based on the comparison of the middle element with the rightmost element
    # search continues until the pointers left and right converge
    while left < right:

        mid = (left + right) // 2  # calculate mid index

        if nums[mid] > nums[right]:
            # min must be at right half
            # e.g. [4, 5, 6, 7, 8(mid), 0, 1, 2, 3(right)]
            left = mid + 1 # update left
        
        elif nums[mid] < nums[right]:
            # min must be at left half
            # e.g. [7, 8, 0, 1, 2(mid), 3, 4, 5, 6(right)]
            right = mid # update right
        
        else: # nums[mid] == nums[right]
            # cannot determine which side: REDUCE SEARCH SPACE ONE BY ONE
            right -= 1

    # after while loop, LEFT WILL POINT TO THE MINIMUM ELEMENT
    # binary search logic ensures that left is always moving toward the minimum element,
    # and when left meets right, we have found the minimum
    return nums[left]

# Function to test the `findMin` function with example cases
def main():
    # Example 1
    nums1 = [1, 3, 5]
    print("Minimum in [1, 3, 5]:", findMin(nums1))  # Output: 1

    # Example 2
    nums2 = [2, 2, 2, 0, 1]
    print("Minimum in [2, 2, 2, 0, 1]:", findMin(nums2))  # Output: 0

    # Additional Example 1
    nums3 = [4, 5, 6, 7, 0, 1, 2]
    print("Minimum in [4, 5, 6, 7, 0, 1, 2]:", findMin(nums3))  # Output: 0

    # Additional Example 2
    nums4 = [10, 1, 10, 10, 10]
    print("Minimum in [10, 1, 10, 10, 10]:", findMin(nums4))  # Output: 1

# Call the main function to run the tests
if __name__ == "__main__":
    main()

"""
0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week08 (main)
$ python findmin_rsarr.py
Minimum in [1, 3, 5]: 1
Minimum in [2, 2, 2, 0, 1]: 0
Minimum in [4, 5, 6, 7, 0, 1, 2]: 0
Minimum in [10, 1, 10, 10, 10]: 1
"""