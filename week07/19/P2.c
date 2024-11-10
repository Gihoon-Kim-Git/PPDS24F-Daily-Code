#include <stdio.h>
#include <stdlib.h>

int* quickSort(int* arr, int Size) {
    if (Size <= 1) return arr;
    int* low = (int*)malloc(sizeof(int) * (Size-1));
    int* high = (int*)malloc(sizeof(int) * (Size-1));
    int pivot = arr[0], i = 0, j = 0;
    while (i+j+1 < Size) {
        if (arr[i+j+1] <= pivot) {
            low[i] = arr[i+j+1];
            i++;
        } else {
            high[j] = arr[i+j+1];
            j++;
        }
    }
    low = quickSort(low, i);
    high = quickSort(high, j);
    for (int k=0; k<Size; k++) {
        if (k < i) arr[k] = low[k];
        else if (k == i) arr[k] = pivot;
        else arr[k] = high[k-i-1];
    }
    free(low);
    free(high);
    return arr;
}

int main() {
    int arr[] = {2, 1, 6, 10, 4, 1, 3, 9, 7};
    int Size = sizeof(arr) / sizeof(arr[0]);
    int* result = quickSort(arr, Size);
    for (int i=0; i<Size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    return 0;
}