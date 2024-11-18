def maximalSquare(matrix):
    if not matrix or not matrix[0]: return 0

    m, n = len(matrix), len(matrix[0])
    dp = [[0]*n for _ in range(m)]    # keep track of the largest square ending at each position in the matrix (i,j가 정사각형의 오른쪽 아래 칸이라 가정)
    max_side = 0      # largest square's side length

    for i in range(m):
        for j in range(n):
            if matrix[i][j] == "1":
                if i==0 or j==0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1    # 자기가 위, 왼쪽 대각선, 왼쪽이 전부 1이면 square의 변 길이가 1 늘어남
                max_side = max(max_side, dp[i][j])

    return max_side * max_side