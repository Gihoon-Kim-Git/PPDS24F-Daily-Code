class Solution:
    def reverseBits(self, n):
        result = 0
        for i in range(1, 33):
            result += (n % 2) * 2 ** (32-i)
            n = int(n / 2)
        return result

if __name__ == "__main__":
    n1 = 0b00000010100101000001111010011100
    n2 = 0b11111111111111111111111111111101
    result = Solution()
    print(result.reverseBits(n1))
    print(result.reverseBits(n2))