from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Custom comparator function
        def compare(x, y):
            if x + y > y + x:
                return -1
            elif x + y < y + x:
                return 1
            else:
                return 0

        # Convert numbers to strings for concatenation and sorting
        nums = list(map(str, nums))
        # Sort the numbers using the custom comparator
        nums.sort(key=cmp_to_key(compare))
        # Join sorted numbers to form the largest number
        result = ''.join(nums)
        # Handle edge case where result is '0' (e.g., nums = [0, 0])
        return '0' if result[0] == '0' else result
