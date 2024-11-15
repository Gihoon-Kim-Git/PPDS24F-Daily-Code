int max(const int a, const int b) {
    return (a < b) ? b : a;
}

int min(const int a, const int b) {
    return (a < b) ? a : b;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int dp[rows+1][cols+1];
    int max_side = 0;

    for (int i=0; i <= rows; i++) {
        for (int j=0; j <= cols; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i=0; i < rows; i++) {
        for (int j=0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                dp[i+1][j+1] = 1+ min(dp[i][j], min(dp[i+1][j], dp[i][j+1]));
                max_side = max(max_side, dp[i+1][j+1]);
            }
        }
    }    
    return max_side * max_side;
}