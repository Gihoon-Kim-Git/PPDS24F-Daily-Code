#include <stdio.h>
#include <stdlib.h>


int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maximalSquare(char** matrix, int n_row, int n_col) {
    int** mtx = (int**)malloc(n_row * sizeof(int*));
    for (int i = 0; i < n_row; i++) {
        mtx[i] = (int*)malloc(n_col * sizeof(int));
    }

    int squareMax = 0;
    for (int i = 0; i < n_row; i++) {
        for (int j = 0; j < n_col; j++) {
            mtx[i][j] = matrix[i][j] - '0';
            if (mtx[i][j] == 1) {
                squareMax = 1;
            }
        }
    }

    for (int i = 1; i < n_row; i++) {
        for (int j = 1; j < n_col; j++) {
            if (mtx[i][j] == 1) {
                int squareMin = min(min(mtx[i-1][j], mtx[i][j-1]), mtx[i-1][j-1]);
                if (squareMin > 0) mtx[i][j] = squareMin + 1;
                squareMax = max(squareMax, mtx[i][j]);
            }
        }
    }

    for (int i = 0; i < n_row; i++) free(mtx[i]);
    free(mtx);

    return squareMax * squareMax;
}

int main() {
    int n_row = 4, n_col = 5;
    char* matrix[] = {
        "10100",
        "10111",
        "11111",
        "10010"
    };

    char** matrix_ptr = (char**)malloc(n_row * sizeof(char*));
    for (int i = 0; i < n_row; i++) {
        matrix_ptr[i] = matrix[i];
    }

    printf("%d\n", maximalSquare(matrix_ptr, n_row, n_col));
    free(matrix_ptr);
    return 0;
}