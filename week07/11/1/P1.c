#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* result = (int*)malloc(sizeof(int) * (*returnSize));

    for(int i = 0; i<=rowIndex; i++){
        //어차피 i가 0,1일때는 아래 for문은 안돌아가므로 그냥 1로 설정만 하는거임
        result[i] = 1;
        for(int j = i-1; j>0 ; j--){
            result[j]+= result[j-1];
        }
    }
    return result;
}



int main(void) {
    int rowIndex = 5;
    int returnSize;
    int* result = getRow(rowIndex, &returnSize);

    printf("Row %d of Pascal's Triangle: [", rowIndex);
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }

    printf("]\n");
    free(result);
    return 0;
}