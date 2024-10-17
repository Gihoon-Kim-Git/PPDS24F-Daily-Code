#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    if (rowIndex == 0) {
        *returnSize = 1;
        int* row = (int*)malloc(*returnSize * sizeof(int));
        row[0] = 1;
        return row;
    } else if (rowIndex == 1) {
        *returnSize = 2;
        int* row = (int*)malloc(*returnSize * sizeof(int));
        row[0] = 1;
        row[1] = 1;
        return row;
    } else {
        int* previous = getRow(rowIndex - 1, returnSize);
        int currentSize = *returnSize + 1;
        int* current = (int*)malloc(currentSize * sizeof(int));
        current[0] = 1;

        for (int i = 1; i < *returnSize; i++) {
            current[i] = previous[i] + previous[i - 1];
        }
        current[currentSize - 1] = 1;

        free(previous);
        *returnSize = currentSize;
        return current;
    }
}