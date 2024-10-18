#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// [1] 목표값을 2D 행렬에서 찾는 함수
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    // [1.1] 행렬의 크기를 이용하여 초기 위치 설정 (오른쪽 위 코너)
    int row = 0;
    int col = *matrixColSize - 1;

    // [1.2] 행렬 내에서 범위를 벗어나지 않는 동안 반복
    while (row < matrixSize && col >= 0) {
        // [1.3] 현재 위치의 값이 목표값인 경우
        if (matrix[row][col] == target) {
            return true;
        }
        // [1.4] 현재 위치의 값이 목표값보다 크면 왼쪽으로 이동
        else if (matrix[row][col] > target) {
            col--;
        }
        // [1.5] 현재 위치의 값이 목표값보다 작으면 아래로 이동
        else {
            row++;
        }
    }
    
    // [1.6] 목표값을 찾지 못한 경우
    return false;
}

// [2] 2D 행렬을 출력하는 함수
void print2D(int** matrix, int rowN, int colN) {
    for (int i = 0; i < rowN; i++) {
        for (int j = 0; j < colN; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // [1] 행렬의 크기 입력 받기
    int rowN, colN, target;
    printf("Type row N: ");
    scanf("%d", &rowN);
    printf("Type col N: ");
    scanf("%d", &colN);
    
    // [2] 넣을거 만들기
    int** matrix = (int**)malloc(rowN * sizeof(int*));
    for (int i = 0; i < rowN; i++) {
        matrix[i] = (int*)malloc(colN * sizeof(int));
        printf("Type the %d th row : ", i);
        for (int j = 0; j < colN; j++) {
            scanf("%d", &(matrix[i][j]));
        }
    }

    // [3] target
    printf("Type target value: ");
    scanf("%d", &target);

    printf("Given matrix:\n");
    print2D(matrix, rowN, colN);

    // [4] searchMatrix 함수
    bool result = searchMatrix(matrix, rowN, &colN, target);
    
    // [5] 결과 출력
    if (result) {
        printf("Target %d found in the matrix.\n", target);
    } else {
        printf("Target %d not found in the matrix.\n", target);
    }

    // 마무으리
    for (int i = 0; i < rowN; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0; 
}
