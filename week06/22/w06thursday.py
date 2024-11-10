class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        result = 0
        for i in range(32):
            bit = n & 1
            result = (result << 1) | bit
            n >>= 1
        return result