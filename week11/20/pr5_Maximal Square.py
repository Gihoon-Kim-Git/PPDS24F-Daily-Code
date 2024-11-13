from typing import List
class Solution:
    def maximalSquare(self, matrix: list[list[str]]) -> int:
        # dp를 어떻게 적용할 지는 모르겠다.
        m = len(matrix)
        n = len(matrix[0])
        ans = 0
        # 좌표 (i,j,cnt->처음 시작 1)를 집어넣다.
        def square(i:int,j:int,cnt:int) -> int :
            # 정사각형이 틀을 벗어나는 경우
            if i+cnt > n-1 or j+cnt > m-1  or matrix[j][i+cnt]=="0" : return cnt*cnt

            for p in range(1,cnt+1):
                if matrix[j+p][i+cnt] == "0":
                    return cnt*cnt

            for q in range(1,cnt+1):
                if matrix[j+cnt][i+cnt-q] == "0":
                    return cnt*cnt

            return square(i,j,cnt+1)
    
        # for 전체를 돌며 1인 놈만 체크해서 아래부분을 훑는 Square search method를 실행한다.
        for i in range(n):
            for j in range(m):
                if matrix[j][i] == "1":
                    ans = max(ans,square(i,j,1))

        return ans

#DP
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m = len(matrix)
        n = len(matrix[0])

        # Using DP! initialize
        dp = [[0] * n for _ in range(m)] # 현재 위치에서 만들 수 있는 최대 정사각형의 길이
        ans = 0

        # Do DP for each cell
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    if i==0 or j==0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1 # why?
                ans = max(ans,dp[i][j])
        return ans*ans