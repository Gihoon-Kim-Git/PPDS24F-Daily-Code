# leetcode 1611. Minimum One Bit Operations to Make Integers Zero
def minimumOneBitOperations(n: int) -> int:
    def helper(x):
        if x == 0:
            return 0
        b = x.bit_length() - 1
        mask = (1 << b) | (1 << (b - 1))
        return (1 << (b + 1)) - 1 - helper(x ^ mask)

    return helper(n)
