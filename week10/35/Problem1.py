# leetcode 375
class Solution:
    def getMoneyAmount(self, n: int) -> int:
        # Create a 2D array to store the minimum cost for each range [i,j]
        dp = [[0]*(n+1) for _ in range(n+1)]

        # Fill the table for ranges of length from 2 to n
        for length in range(2,n+1):
            for start in range(1,n-length+2):
                end = start + length - 1
                dp[start][end]=float('inf')
                for k in range(start, end):
                    cost = k + max(dp[start][k-1],dp[k+1][end])
                    dp[start][end] = min(dp[start][end],cost)
        return dp[1][n]