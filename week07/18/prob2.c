#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j <= high-1; j++){
        if (arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } 
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

//Function to sort an array using quick sort algorithm.
void quickSort(int arr[], int low, int high){
    if (low<high){
        int pivot_index = partition(arr, low, high);

        quickSort(arr, low, pivot_index-1);
        quickSort(arr, pivot_index+1, high);
    } 
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s T n1 n2 ... nT\n", argv[0]);
        return 1;  // Return an error if arguments are insufficient
    }

    int T = atoi(argv[1]);  // Number of test cases

    if (T < 1) {
        printf("Invalid number of test cases.\n");
        return 1;
    }

    srand(time(0));  // Seed for random number generation

    for (int t = 0; t < T; t++) {
        int n = atoi(argv[t + 2]);  // Array length for the t-th test case

        if (n <= 0 || n > 1000) {
            printf("Invalid array length for test case %d. It must be between 1 and 1000.\n", t + 1);
            continue;  // Skip this test case if the array length is invalid
        }

        int arr[n];

        // Generate random numbers for the array
        printf("\nTest Case %d: Array of length %d\n", t + 1, n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;  // Generate random numbers between 0 and 99
        }

        // Print the original array
        printf("Original array: ");
        printArray(arr, n);

        // Sort the array using quickSort
        quickSort(arr, 0, n - 1);

        // Print the sorted array
        printf("Sorted array: ");
        printArray(arr, n);
    }

    return 0;
}