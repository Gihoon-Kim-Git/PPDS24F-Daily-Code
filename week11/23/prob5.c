#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int minimal(int a, int b, int c) {
    int min = a < b ? a : b;
    return min < c ? min : c;
}

int maximalSquare(char** matrix, int m, int n) {
    if (m == 0 || n == 0) return 0;

    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    int max_side = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = minimal(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                }
                if (dp[i][j] > max_side) max_side = dp[i][j];
            }
        }
    }
    return max_side * max_side;
}

int main() {
    int m = 4, n = 5;
    char* matrix[] = {
        "10100",
        "10111",
        "11111",
        "10010"
    };
    
    printf("%d\n", maximalSquare(matrix, m, n));  // Output: 4
    return 0;
}
