class Solution:
    def getMoneyAmount(self, n: int) -> int:
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        
        for length in range(2, n + 1):  # Length of the range
            for start in range(1, n - length + 2):  # Starting point of the range
                end = start + length - 1
                min_cost = float('inf')
                
                for pivot in range(start, end):  # Trying each pivot within the range
                    cost = pivot + max(dp[start][pivot - 1], dp[pivot + 1][end])
                    min_cost = min(min_cost, cost)
                
                dp[start][end] = min_cost  # Minimum cost for this range

        return dp[1][n]  # Minimum cost for the range 1 to n