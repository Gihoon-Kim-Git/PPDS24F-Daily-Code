#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high);

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//Function to sort an array using quick sort algorithm.
int* quickSort(int arr[], int low, int high)
{
    // code here
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi+1, high);   
    }
    return arr;
}
    
int partition (int arr[], int low, int high)
{
   // Your code here
   int piv = arr[high];
   int i = low;
   for (int j = low; j < high; j++){
    if(arr[j] <= piv){
        swap(&arr[j], &arr[i]);
        i++;
    }
   }
   swap(&arr[high], &arr[i]);

   return i;
}

int main(void) {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sorting the array
    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}