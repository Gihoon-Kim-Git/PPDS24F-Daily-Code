# max product of three
class Solution:
    def maxProductOfThree(self, A):
        if len(A) < 3:
            return 0
        
        max1 = max2 = max3 = float('-inf')
        min1 = min2 = float('inf')
        
        for num in A:
            if num > max1:
                max3, max2, max1 = max2, max1, num
            elif num > max2:
                max3, max2 = max2, num
            elif num > max3:
                max3 = num
            
            if num < min1:
                min2, min1 = min1, num
            elif num < min2:
                min2 = num
        
        return max(max1 * max2 * max3, max1 * min1 * min2)
    
        # A.sort()
        # return max(A[-1] * A[-2] * A[-3], A[0] * A[1] * A[-1])







