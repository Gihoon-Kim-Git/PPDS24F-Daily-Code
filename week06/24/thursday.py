class Solution:
    def reverseBits(self, n: int) -> int:
        result = 0
        for i in range(32):
            # Extract the least significant bit of n and shift it to the correct position
            result = (result << 1) | (n & 1)
            # Shift n right by 1 to process the next bit
            n >>= 1
        return result