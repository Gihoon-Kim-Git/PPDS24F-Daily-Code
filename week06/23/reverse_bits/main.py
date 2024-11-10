class Solution:
    def reverseBits(self, n: int) -> int:
        result = 0
        for i in range(32):
            # Extract the least significant bit of n
            bit = n & 1
            # Shift result to the left and add the extracted bit
            result = (result << 1) | bit
            # Shift n to the right to process the next bit
            n >>= 1
        return result

sol = Solution()
n = 43261596
print(sol.reverseBits(n))

# Output: 964176192 (in binary: 00111001011110000010100101000000)
