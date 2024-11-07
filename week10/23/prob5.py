# 1611. Minimum One Bit Operations to Make Integers Zero
class Solution(object):
    def minimumOneBitOperations(self, n):
        f = [0] * 31
        f[0] = 1
        for i in range(1, 31):
            f[i] = 2 * f[i - 1] + 1

        ans = 0
        count = 0
        for i in range(30, -1, -1):
            if (1 << i) & n != 0:
                count += 1
                if count % 2 == 1:
                    ans += f[i]
                else:
                    ans -= f[i]

        return ans
        