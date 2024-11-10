class Solution(object):
   def minimumOneBitOperations(self, n):
       if n == 0:
           return 0
           
       k = 0
       curr = n
       while curr > 1:
           curr >>= 1
           k += 1
           
       return ((1 << (k + 1)) - 1) - self.minimumOneBitOperations(n ^ (1 << k))