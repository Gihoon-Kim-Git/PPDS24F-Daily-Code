class Solution:
    def reverseBits(self, n: int) -> int:
        lst = []
        for i in range(32):
            lst.append(n%2)
            n >>= 1

        ans = 0
        for i in range(32):            
            ans <<= 1
            ans += lst[i]
        
        return ans