class Solution:
    def reverseBits(self, n):
        result = 0
        for i in range(32):
            # Extract the least significant bit (LSB) of n and append it to result
            result = (result << 1) | (n & 1)
            # Right shift n to process the next bit
            n >>= 1
        return result