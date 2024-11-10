/*<문제>
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

<constraint>
    m == matrix.length
    n == matrix[i].length
    1 <= n, m <= 300
    -109 <= matrix[i][j] <= 109
    All the integers in each row are sorted in ascending order.
    All the integers in each column are sorted in ascending order.
    -109 <= target <= 109
*/

/*풀이 : stepwise search
    1. 초기값 : col = len_n-1, row = 0
    2. matrix 우측 최상단에서 시작해서 target값과 비교.
        while (col >= 0 and row <= len(matrix))
            만약 해당 값 == target : return True
            else if 해당값 < target : col--
            else 해당값 > target : row ++
    3. 

*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int col = *matrixColSize-1;
    int row = 0;

    while (col >= 0 && row < matrixSize){
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] >  target) col--;
        else row++;
    }
    return false;
}