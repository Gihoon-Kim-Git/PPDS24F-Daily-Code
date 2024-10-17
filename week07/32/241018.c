bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row=0, col = *matrixColSize - 1;
    while (col >= 0 && row <= matrixSize-1) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            row++;
        } else {
            col--;
        }
    }
    return false;
}