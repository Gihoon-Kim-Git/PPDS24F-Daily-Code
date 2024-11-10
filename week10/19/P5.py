class Solution1(object):
    def minimumOneBitOperations(self, n):
        dp = [0] * (n+1)
        for i in range(1, n+1):
            bit = i.bit_length() - 1
            dp[i] = 2**(bit+1) - 1 - dp[i - 2**bit]
        return dp[n]

class Solution2(object):
    def minimumOneBitOperations(self, n):
        dp = {0: 0}

        def recursion(n):
            if n not in dp:
                b = 2 ** (n.bit_length() - 1)
                dp[n] = recursion((b >> 1) ^ b ^ n) + b
            return dp[n]
        
        return recursion(n)

if __name__ == "__main__":
    result = Solution1()
    # result = Solution2()
    print(result.minimumOneBitOperations(3)) # 2
    # print(result.minimumOneBitOperations(6)) # 4
    # print(result.minimumOneBitOperations(9)) # 14