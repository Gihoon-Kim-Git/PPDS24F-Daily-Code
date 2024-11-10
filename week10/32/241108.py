class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n == 0:
            return 0
        
        k = 0
        while (1 << k) <= n:
            k += 1
        k -= 1
        
        return ((1 << (k + 1)) - 1 - self.minimumOneBitOperations(n ^ (1 << k)))