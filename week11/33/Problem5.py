# m x n matrix가 주어져있을 때 1인 element만을 포함하는 정사각형 영역의 넓이 구하기

"""
time out
"""
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        row, col = len(matrix), len(matrix[0])
        ans = 0

        def isValid(i, j, leng):
            for ix in range(leng):
                for jx in range(leng):
                    if i+ix >= row or j+jx >= col or matrix[i+ix][j+jx] != "1":
                        return False
            return True

        for i in range(row):
            for j in range(col):
                length = 0
                if matrix[i][j] == "1":
                    length += 1
                    while isValid(i, j, length+1):
                        length += 1
                ans = max(ans, length)
        return ans * ans
        

"""
GPT 코드
: 현재 위치에서 만들 수 있는 최대 정사각형 크기 저장
O O
O X -> X위치일 때를 기준으로
"""
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        
        row, col = len(matrix), len(matrix[0])
        dp = [[0] * (col + 1) for _ in range(row + 1)]
        max_side = 0
        
        for i in range(1, row + 1):
            for j in range(1, col + 1):
                if matrix[i-1][j-1] == "1":
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    max_side = max(max_side, dp[i][j])
        
        return max_side * max_side