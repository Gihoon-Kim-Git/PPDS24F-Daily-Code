/* dp로 풀이.
    1. dpT을 input matrix와 같은 모양으로 초기화. 초깃값 전부 0
    2. input matrix의 width(j), height(i)에 대해 for문을 돌면서, 갱신을 하는데. 
        만약 matrix[i][j] == 1이면 dpT[i][j] =1 + min(matrix[i-1][j], matrix[i][j-1], matrix[i][j])
    3. dpT를 다 채우면 dpT안에서의 최댓값을 찾아서 반환.
        (dpT를 채워가면서 동시에 최댓값을 갱신하는 편이 더 낫겠다.)
*/

#include <stdio.h>
#include <stdlib.h>

//★ min_three 정의에 매우 유의.!!!!
#define min(a,b) ((a) < (b) ? (a) : (b))
#define min_three(a,b,c) (min(min((a),(b)), (c)))

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    //dpT 초기화
    int** dpT = (int**)malloc(sizeof(int*)*matrixSize);
    for (int i = 0; i < matrixSize; i++){
        int* row = (int*)calloc((*matrixColSize), sizeof(int));
        dpT[i] = row;
    }
    // 갱신할 max값
    int max_side = 0;

    for (int j = 0; j < (*matrixColSize);j++){
        if (matrix[0][j] == '1') {//"1"이아니라 '1'로 해야함에 매우 유의
            dpT[0][j] = 1;
            max_side = 1;    
        }
    }

    for (int i = 0 ; i < matrixSize ;i++) {
        if (matrix[i][0] == '1') {
            dpT[i][0] = 1;
            max_side = 1;    
        }
    }

    for (int i = 1; i < matrixSize; i++){
        for (int j = 1; j < (*matrixColSize); j++){
            if (matrix[i][j] == '1') dpT[i][j] = 1 + min_three(dpT[i-1][j], dpT[i][j-1], dpT[i-1][j-1]);
            if (dpT[i][j] > max_side) max_side = dpT[i][j];
        }
    }

    for (int i = 0; i < matrixSize; i++){
        free(dpT[i]);
    }
    free(dpT);

    return max_side*max_side;

}