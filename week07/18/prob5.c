#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int m = matrixSize;
    int n = *matrixColSize;

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (matrix[i][j] == target){
                return true;}
            else if (matrix[i][j] > target){
                break;}
        }
    }

    return false;
}