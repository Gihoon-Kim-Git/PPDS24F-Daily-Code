#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = matrixSize - 1;
    int col = 0;

    while (row >= 0 && col < *matrixColSize){
        if(matrix[row][col] == target){
            return true;
        }
        else if(matrix[row][col] > target){
            row--;
        }
        else if(matrix[row][col] < target){
            col++;
        }
    }
    return false;
}


int main() {
    // 테스트 케이스 1
    int matrix1[3][3] = {
        {1, 4, 7},
        {8, 11, 15},
        {18, 21, 23}
    };
    int* matrix1Ptr[3] = {matrix1[0], matrix1[1], matrix1[2]};
    int cols1 = 3;
    printf("Test Case 1: %s\n", searchMatrix(matrix1Ptr, 3, &cols1, 11) ? "Found" : "Not Found");

    // 테스트 케이스 2
    int matrix2[4][4] = {
        {2, 5, 8, 12},
        {9, 13, 15, 19},
        {20, 23, 26, 30},
        {31, 34, 38, 41}
    };
    int* matrix2Ptr[4] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3]};
    int cols2 = 4;
    printf("Test Case 2: %s\n", searchMatrix(matrix2Ptr, 4, &cols2, 26) ? "Found" : "Not Found");

    // 테스트 케이스 3
    int matrix3[2][3] = {
        {1, 3, 5},
        {7, 9, 11}
    };
    int* matrix3Ptr[2] = {matrix3[0], matrix3[1]};
    int cols3 = 3;
    printf("Test Case 3: %s\n", searchMatrix(matrix3Ptr, 2, &cols3, 4) ? "Found" : "Not Found");

    return 0;
}