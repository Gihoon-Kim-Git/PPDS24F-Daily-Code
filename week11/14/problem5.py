# week 11

# Friday. [Maximal Square](https://leetcode.com/problems/maximal-square/description/)

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m,n=len(matrix),len(matrix[0])
        dp=[[0 for i in range(n+1)] for j in range(m+1)]
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if matrix[i][j]!='1': continue
                dp[i][j]=max( dp[i][j], 1+min([dp[i+1][j],dp[i][j+1],dp[i+1][j+1]]) )
        return max(sum(dp,[]))**2