#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int soldiers;
    int index;
} RowStrength;

int compare(const void* a, const void* b) {
    RowStrength* rowA = (RowStrength*)a;
    RowStrength* rowB = (RowStrength*)b;
    if (rowA->soldiers == rowB->soldiers) {
        return rowA->index - rowB->index;
    }
    return rowA->soldiers - rowB->soldiers;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    RowStrength* strengths = (RowStrength*)malloc(matSize * sizeof(RowStrength));

    // Calculate the strength of each row
    for (int i = 0; i < matSize; ++i) {
        int soldier_count = 0;
        for (int j = 0; j < *matColSize; ++j) {
            if (mat[i][j] == 1) soldier_count++;
            else break;  // Stop as soon as we hit 0
        }
        strengths[i] = (RowStrength){soldier_count, i};
    }

    // Sort rows by strength and index
    qsort(strengths, matSize, sizeof(RowStrength), compare);

    // Extract the indices of the k weakest rows
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; ++i) {
        result[i] = strengths[i].index;
    }

    *returnSize = k;
    free(strengths);
    return result;
}

int main() {
    int mat[5][5] = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    int* matPtrs[5];
    for (int i = 0; i < 5; ++i) matPtrs[i] = mat[i];
    int matColSize = 5, returnSize;
    int* result = kWeakestRows(matPtrs, 5, &matColSize, 3, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    // Output: 2 0 3

    free(result);
    return 0;
}
