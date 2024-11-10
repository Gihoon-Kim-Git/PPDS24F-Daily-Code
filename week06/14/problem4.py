## Thursday. [Reverse Bits](https://leetcode.com/problems/reverse-bits/description/)

class Solution:
    def reverseBits(self, n: int) -> int:
        bin_n = bin(n)[2:]
        while len(bin_n) < 32:
            bin_n = '0'+bin_n
        return int('0b' + bin_n[::-1], 2)