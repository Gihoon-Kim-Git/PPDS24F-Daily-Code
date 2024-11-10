# week 10

# Friday. [Minimum One Bit Operations to Make Integers Zero](https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/)

class Solution:

    def AnyToZero(self, s): # n-bit string -> zero
        if len(s)==1: return int(s[0]=='1')

        if s[0]=='1':
            return self.AnyToPower(s[1:])+1+self.PowerToZero(len(s[1:]))
        else:
            return self.AnyToZero(s[1:])

    def AnyToPower(self, s): # n-bit string -> 1 + (n-1)-bit zeros
        if len(s)==1: return int(s[0]=='0')

        if s[0]=='1':
            return self.AnyToZero(s[1:])
        else:
            return self.AnyToPower(s[1:])+1+self.PowerToZero(len(s[1:]))

    def PowerToZero(self, n): # n-bit 10000...0 -> 0
        return 2**n-1

    def minimumOneBitOperations(self, num: int) -> int:
        return self.AnyToZero(bin(num)[2:])