class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        dp = [[] for _ in range(rowIndex+1)]
        dp[0] = [1]
        for i in range(1, rowIndex + 1):
            dp[i] += [1]
            for j in range(1, len(dp[i-1])):
                dp[i] += [dp[i-1][j-1] + dp[i-1][j]]
            dp[i] += [1]
        return dp[-1]