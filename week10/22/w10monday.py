class Solution(object):
    def getMoneyAmount(self, n):
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        
        for length in range(2, n + 1):
            for start in range(1, n - length + 2):
                end = start + length - 1
                dp[start][end] = float('inf')
                for x in range(start, end + 1):
                    cost = x + max(dp[start][x-1] if x > start else 0, 
                                 dp[x+1][end] if x < end else 0)
                    dp[start][end] = min(dp[start][end], cost)
        
        return dp[1][n]