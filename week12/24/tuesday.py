# Largest Number
from typing import List
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Convert numbers to strings
        str_nums = map(str, nums)
        
        # Sort strings in descending order based on concatenation comparison
        sorted_nums = sorted(str_nums, key=lambda x: x*10, reverse=True)
        
        # Join the sorted strings
        joined = "".join(sorted_nums)
        
        # Convert to int and back to string to remove leading zeros
        result = str(int(joined))
        
        return result