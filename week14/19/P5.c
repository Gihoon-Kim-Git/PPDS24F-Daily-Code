#include <stdio.h>
#include <stdlib.h>

void reverse(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int* pancakeSort(int* arr, int arrSize, int* returnSize) {
    int* result = (int*)malloc(arrSize * 2 * sizeof(int));
    int resultIndex = 0;
    int end = arrSize - 1;
    while (end > 0) {
        int maxVal = arr[0];
        int maxIdx = 0;
        for (int i = 0; i <= end; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
                maxIdx = i;
            }
        }
        result[resultIndex++] = maxIdx + 1;
        reverse(arr, 0, maxIdx);
        result[resultIndex++] = end + 1;
        reverse(arr, 0, end);
        end--;
    }
    *returnSize = resultIndex;
    return result;
}

int main() {
    int arr[] = {3, 2, 4, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int returnSize;
    int* result = pancakeSort(arr, arrSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}