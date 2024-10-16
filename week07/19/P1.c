#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    result[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        result[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            result[j] = result[j] + result[j - 1];
        }
    }
    return result;
}

int main() {
    int rowIndex = 5;
    int returnSize;
    int* row = getRow(rowIndex, &returnSize);
    for (int i=0; i<returnSize; i++) {
        printf("%d ", row[i]);
    }
    printf("\n");
    free(row);

    return 0;
}