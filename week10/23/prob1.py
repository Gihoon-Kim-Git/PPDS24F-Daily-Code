# 375. Guess Number Higher or Lower II
class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp, length = [[0] * (n + 2) for _ in range(n + 2)], 2
        for i in range(1, n): dp[i][i + 1] = i
            
        while length < n:
            for i in range(1, n + 1 - length):
                dp[i][i + length] = min(
                    l + max(dp[i][l - 1], dp[l + 1][i + length]) for l in range(i, i + length + 1)
                )
                
            length += 1
            
        return dp[1][n]   