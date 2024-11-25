"""
<Largest Number>

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.
"""


def largestNumber(nums):
    nums = list(map(str, nums))
    nums.sort(key=lambda x: x * 10, reverse=True)
    largest_num = ''.join(nums)
    return '0' if largest_num[0] == '0' else largest_num

nums = [3, 30, 34, 5, 9]
print(largestNumber(nums))  #"9534330"
