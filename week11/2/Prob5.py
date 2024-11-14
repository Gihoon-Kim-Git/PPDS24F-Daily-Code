from typing import List

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n_col = len(matrix[0])
        n_row = len(matrix)
        dp = [[0 for _ in range(n_col+1)] for _ in range(n_row+1)]
        result = 0
        for i in range(1, n_row+1):
            for j in range(1, n_col+1):
                if matrix[i-1][j-1] == "1":
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j-1], dp[i-1][j]) + 1
                    result = max(result, dp[i][j])
        
        return result**2
