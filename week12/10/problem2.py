from collections import List  

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        
        arr = list(map(str, nums))
        arr.sort(key=lambda x: x*10, reverse=True)
        if arr[0] == "0":
            return "0"
        
        largest = ''.join(arr)

        return largest