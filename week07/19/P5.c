#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrixHelp(int** matrix, int matrixSize, int* matrixColSize, int row, int col, int target){
    if (matrix[row][col] > target) return false;
    if (matrix[row][col] == target) return true;
    bool a, b;
    if (matrix[row][col] < target) {
        if (row+1 < matrixSize) {
            a = searchMatrixHelp(matrix, matrixSize, matrixColSize, row+1, col, target);
        }
        if (col+1 < *matrixColSize) {
            b = searchMatrixHelp(matrix, matrixSize, matrixColSize, row, col+1, target);
        }
    }
    return a || b;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (matrix[0][0] > target) return false;
    bool result = searchMatrixHelp(matrix, matrixSize, matrixColSize, 0, 0, target);
    return result;
}

int main() {
    int rows = 5, cols = 5;
    int* matrixColSize = (int*)malloc(sizeof(int) * rows);
    for (int i = 0; i < rows; i++) matrixColSize[i] = cols;
    int** matrix = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) matrix[i] = (int*)malloc(sizeof(int) * cols);
    int values[5][5] = {{1, 4, 7, 11, 15},
                        {2, 5, 8, 12, 19},
                        {3, 6, 9, 16, 22},
                        {10, 13, 14, 17, 24},
                        {18, 21, 23, 26, 30}};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = values[i][j];
        }
    }

    printf("%d\n", searchMatrix(matrix, rows, matrixColSize, 5));  // 출력: 1 (true)
    printf("%d\n", searchMatrix(matrix, rows, matrixColSize, 20)); // 출력: 0 (false)

    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);
    free(matrixColSize);

    return 0;
}