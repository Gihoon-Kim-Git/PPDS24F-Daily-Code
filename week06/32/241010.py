class Solution:
    def reverseBits(self, n: int) -> int:
        result = 0
        for i in range(1, 33):
            resi = n & 1
            result += resi << (32-i)
            n = n >> 1
        return result