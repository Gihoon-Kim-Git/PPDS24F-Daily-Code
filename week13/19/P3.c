#include <stdio.h>
#include <stdlib.h>

struct RowInfo {
    int index;
    int count;
};

int compare(const void *a, const void *b) {
    struct RowInfo *rowA = (struct RowInfo *)a;
    struct RowInfo *rowB = (struct RowInfo *)b;
    if (rowA->count != rowB->count) {
        return rowA->count - rowB->count;
    }
    return rowA->index - rowB->index;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    struct RowInfo* rows = (struct RowInfo*)malloc(matSize * sizeof(struct RowInfo));
    for (int i = 0; i < matSize; i++) {
        rows[i].index = i;
        rows[i].count = 0;
        for (int j = 0; j < *matColSize; j++) {
            rows[i].count += mat[i][j];
        }
    }
    qsort(rows, matSize, sizeof(struct RowInfo), compare);
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = rows[i].index;
    }
    *returnSize = k;

    free(rows);
    return result;
}

int main() {
    int matData[5][5] = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };

    int matSize = 5;
    int matColSize[] = {5, 5, 5, 5, 5};
    int* mat[5];
    for (int i = 0; i < 5; i++) {
        mat[i] = matData[i];
    }

    int k = 3;
    int returnSize;
    int* result = kWeakestRows(mat, matSize, matColSize, k, &returnSize);

    printf("The %d weakest rows are: ", k);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}