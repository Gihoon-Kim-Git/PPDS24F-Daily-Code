#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || *matrixColSize == 0) {
        return 0;
    }

    int maxSide = 0;  // 가장 큰 정사각형의 한 변의 길이
    int rows = matrixSize;
    int cols = *matrixColSize;

    // DP 배열 초기화
    int** dp = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        dp[i] = (int*)malloc(sizeof(int) * cols);
        memset(dp[i], 0, sizeof(int) * cols);  // 각 행을 0으로 초기화
    }

    // 동적 프로그래밍을 통해 각 위치에서 가능한 가장 큰 정사각형을 계산
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {  // '1'인 경우에만 처리
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;  // 첫 번째 행이나 열에 있을 때는 1로 초기화
                } else {
                    dp[i][j] = fmin(fmin(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;  // 이전 셀들 중 최소값을 더함
                }
                maxSide = fmax(maxSide, dp[i][j]);  // 최대 크기 업데이트
            }
        }
    }

    // 가장 큰 정사각형의 넓이를 반환
    int result = maxSide * maxSide;

    // 메모리 해제
    for (int i = 0; i < rows; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    char* matrix1[] = {
        "10100",
        "10111",
        "11111",
        "10101"
    };
    int matrixSize1 = 4;
    int matrixColSize1 = 5;

    printf("Maximal Square Area: %d\n", maximalSquare(matrix1, matrixSize1, &matrixColSize1));

    return 0;
}
