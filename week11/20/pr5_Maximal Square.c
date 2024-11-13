#include <stdio.h>
#include <stdlib.h>

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return 0;

    int m = matrixSize;
    int n = matrixColSize[0];
    int maxSide = 0;

    // dp 배열 동적 할당 및 초기화
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
    }

    // DP를 통해 최대 정사각형 한 변의 길이를 계산
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    // 첫 행이나 첫 열의 경우, 그냥 1로 설정
                    dp[i][j] = 1;
                } else {
                    // 위, 왼쪽, 대각선 위-왼쪽의 최소값 + 1
                    dp[i][j] = (dp[i - 1][j] < dp[i][j - 1] ? (dp[i - 1][j] < dp[i - 1][j - 1] ? dp[i - 1][j] : dp[i - 1][j - 1]) : (dp[i][j - 1] < dp[i - 1][j - 1] ? dp[i][j - 1] : dp[i - 1][j - 1])) + 1;
                }
                if (dp[i][j] > maxSide) maxSide = dp[i][j];
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // 메모리 해제
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);

    // 정사각형의 넓이 반환
    return maxSide * maxSide;
}

int main() {
    // 예제 입력 (1은 '1'로, 0은 '0'으로 입력)
    char* matrix[] = {
        "10100",
        "10111",
        "11111",
        "10010"
    };
    int matrixSize = 4;
    int matrixColSize[] = {5, 5, 5, 5};

    int result = maximalSquare(matrix, matrixSize, matrixColSize);
    printf("The area of the largest square is: %d\n", result);

    return 0;
}
