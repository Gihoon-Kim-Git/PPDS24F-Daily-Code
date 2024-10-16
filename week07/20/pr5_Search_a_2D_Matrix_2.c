#include <stdbool.h>
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int m = matrixSize-1;
    int n = *matrixColSize-1;
    int col = 0;
    while(m>=0 && col<=n){
        if(matrix[m][col]==target) return true;
        else if(matrix[m][col] < target) col++;
        else m--;
    }
    return false;
}