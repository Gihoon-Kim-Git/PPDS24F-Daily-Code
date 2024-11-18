#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Problem Description:
 * --------------------
 * Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's
 * and return its area.
 *
 * Examples:
 * ---------
 * Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 4
 *
 * Input: matrix = [["0","1"],["1","0"]]
 * Output: 1
 *
 * Constraints:
 * ------------
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 300
 * matrix[i][j] is '0' or '1'.
 *
 * Approach:
 * ---------
 * 1. Use dynamic programming to calculate the size of the largest square ending at each cell.
 * 2. Define `dp[i][j]` as the size of the largest square whose bottom-right corner is at `(i, j)`.
 *    - If matrix[i][j] == '1', then:
 *      dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
 * 3. Keep track of the maximum size of any square and return its area (size * size).
 */

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize == 0) {
        return 0; // No rows or columns
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int max_side = 0;

    // Allocate a DP table
    int** dp = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        dp[i] = (int*)malloc(cols * sizeof(int));
        memset(dp[i], 0, cols * sizeof(int)); // Initialize to 0
    }

    // Fill the DP table
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1; // Base case for the first row or column
                } else {
                    dp[i][j] = fmin(dp[i - 1][j], fmin(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
                max_side = fmax(max_side, dp[i][j]); // Track the largest side length
            }
        }
    }

    // Free the DP table
    for (int i = 0; i < rows; i++) {
        free(dp[i]);
    }
    free(dp);

    return max_side * max_side; // Return the area of the largest square
}