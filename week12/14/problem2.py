# week 12

# Tuesday. [Largest Number](https://leetcode.com/problems/largest-number/description/)

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Convert integers to strings
        array = list(map(str, nums))
        
        # Custom sorting with a lambda function
        array.sort(key=lambda x: x*10, reverse=True)
        
        # Handle the case where the largest number is "0"
        if array[0] == "0":
            return "0"
        
        # Build the largest number from the sorted array
        largest = ''.join(array)
        
        return largest