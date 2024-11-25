# Question:
# Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
# Since the result may be very large, you need to return it as a string instead of an integer.

# Example 1:
# Input: nums = [10, 2]
# Output: "210"

# Example 2:
# Input: nums = [3, 30, 34, 5, 9]
# Output: "9534330"

# Constraints:
# 1 <= nums.length <= 100
# 0 <= nums[i] <= 10^9

def largestNumber(nums):
    # convert all numbers from int to string
    str_nums = []
    for num in nums:
        str_nums.append(str(num))

    # recursive sorting algorithm: quicksort-like approach
    # sort string converted array
    def custom_sort(str_arr):

        # base case: already sorted (same or less than one element)
        if len(str_arr) <= 1:
            return str_arr
        
        # choose the first element as pivot
        pivot = str_arr[0]
        left = [] # elements smaller than pivot
        right = [] # elements larger than pivot

        # partition array based on custom comparison
        for i in range(1, len(str_arr)):
            # string for placement str_arr[i]: start from second element
            # for each element in the array (except the pivot),
            # compare it with the pivot by concatenating strings in both possible orders
            # e.g. comparison:  934  v.s.  349
            # print("comparison: ", str_arr[i] + pivot, " v.s. ", pivot + str_arr[i])
            if str_arr[i] + pivot > pivot + str_arr[i]:
                # str_arr[i] should come before pivot
                left.append(str_arr[i])
            else:
                # # str_arr[i] should come after pivot
                right.append(str_arr[i])
        
        # recursively sort the left and right partitions
        # then combine with the pivot
        # print("current sorted: ", custom_sort(left) + [pivot] + custom_sort(right))
        return custom_sort(left) + [pivot] + custom_sort(right)
    
    # sort array of num strings
    sorted_nums = custom_sort(str_nums)

    # concatenate sorted numbers into the largest number
    ans = "".join(sorted_nums)

    # handle edge case: largest number is 0
    if ans[0] != "0":
        return ans
    else:
        return "0"
    

# example 1
nums1 = [10, 2]
print(largestNumber(nums1)) # "210"

# example 2
nums2 = [3,30,34,5,9]
print(largestNumber(nums2)) # "9534330"