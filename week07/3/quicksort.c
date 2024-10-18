/*
Problem: Implement Quick Sort

Quick Sort is a Divide and Conquer algorithm that selects a 'pivot' element and partitions the array 
around the pivot such that:
    - All elements less than or equal to the pivot are on the left.
    - All elements greater than the pivot are on the right.

Expected Time Complexity: O(N * log N)
Expected Auxiliary Space: O(log N)
*/

#include <stdio.h>

// Function to partition the array using the last element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1; // Pointer for greater element

    // Traverse the array and compare each element with the pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            // Swap elements
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place the pivot element in the correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the pivot index
}

// Function to perform quicksort on the array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively apply quicksort to left and right partitions
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Example Usage
int main() {
    int arr[] = {4, 1, 3, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}