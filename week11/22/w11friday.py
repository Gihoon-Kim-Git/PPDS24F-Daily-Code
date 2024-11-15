class Solution(object):
    def maximalSquare(self, matrix):
        m, n = len(matrix), len(matrix[0]) if matrix else 0
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        max_len = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i + 1][j], dp[i][j]) + 1
                    max_len = max(max_len, dp[i + 1][j + 1])
        return max_len * max_len