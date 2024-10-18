#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    // 2d -> 1d
    int numRow = matrixSize;
    int numCol = *matrixColSize;

    // matrix[i][j] -> idx = numCol * i + j
    // binarysearch
    int row = 0;
    int col = numCol - 1;
    while(row < numRow && col >= 0)
    {
        if(matrix[row][col]==target)
        {
            return true;
        }
        else if(matrix[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return false;
  
}
int main() {
    // First test matrix
    int matrix1[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    // Second test matrix (your provided matrix)
    int matrix2[5][5] = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int* matrixColSize = (int*)malloc(sizeof(int));
    
    // Test case 1
    *matrixColSize = 4;
    int* matrixPtr1[3];
    for(int i = 0; i < 3; i++) {
        matrixPtr1[i] = matrix1[i];
    }

    int target1 = 16;
    if (searchMatrix(matrixPtr1, 3, matrixColSize, target1)) {
        printf("Target %d found in matrix 1!\n", target1);
    } else {
        printf("Target %d not found in matrix 1!\n", target1);
    }

    // Test case 2 (your provided matrix)
    *matrixColSize = 5;
    int* matrixPtr2[5];
    for(int i = 0; i < 5; i++) {
        matrixPtr2[i] = matrix2[i];
    }

    int target2 = 5;
    if (searchMatrix(matrixPtr2, 5, matrixColSize, target2)) {
        printf("Target %d found in matrix 2!\n", target2);
    } else {
        printf("Target %d not found in matrix 2!\n", target2);
    }

    free(matrixColSize);
    return 0;
}