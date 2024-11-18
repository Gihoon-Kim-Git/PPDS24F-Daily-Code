class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n= len(matrix)
        m = len(matrix[0])

        @cache
        def dfs(i, j):
            if not (0<= i <n and 0 <= j < m and matrix[i][j] == '1'): return 0
            curr = float('inf')
            for x,y in [i+1,j], [i+1, j+1], [i, j+1]:
                curr = min(curr, 1 + dfs(x,y))
            return curr
        ans=0
        for i in range(n):
            for j in range(m):
                if matrix[i][j]=='1':
                    ans = max(ans,dfs(i,j))
        return ans* ans