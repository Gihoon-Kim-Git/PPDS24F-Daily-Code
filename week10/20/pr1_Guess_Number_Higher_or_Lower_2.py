class Solution:
    def getMoneyAmount(self, n: int) -> int:
        # DP table initialization
        dp = [[0]*(n+1) for _ in range(n+1)]

        # fill in the DP
        for length in range(2,n+1):
            for i in range(1,n-length+2):
                j = i + length - 1
                dp[i][j] = float('inf')
                for k in range(i,j):
                    cost = k + max(dp[i][k-1],dp[k+1][j])
                    dp[i][j] = min(dp[i][j],cost)
        return dp[1][n]