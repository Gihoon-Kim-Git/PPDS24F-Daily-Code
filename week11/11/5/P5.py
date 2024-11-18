#%%
class Solution:
    def maximalSquare(self, matrix: list[list[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0

        # 여기서 dp는 i,j에서 끝나는 사각형의 최대 변 길이
        dp = [[0] * len(matrix[0]) for _ in range(len(matrix))]

        #즉, max_side를 계속 추적해야함
        max_side = 0

        # 첫 번째 행과 첫 번째 열 처리
        for i in range(len(matrix)):
            if matrix[i][0] == "1":
                dp[i][0] = 1
                max_side = max(max_side, dp[i][0])
                
        for j in range(len(matrix[0])):
            if matrix[0][j] == "1":
                dp[0][j] = 1
                max_side = max(max_side, dp[0][j])

        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                # 0일땐 어차피 거기서 끝나는 사각형 성립 X
                if matrix[i][j] == "1":
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    max_side = max(max_side, dp[i][j])

        return max_side ** 2