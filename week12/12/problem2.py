from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums):
        nums = [str(x) for x in nums]
        
        def compare(x, y):
            if x + y > y + x:
                return -1 
            elif x + y < y + x:
                return 1  
            else:
                return 0   
        
        nums.sort(key=cmp_to_key(compare))
        
        result = ''.join(nums)
        
        if result[0] == '0':
            return '0'
        
        return result