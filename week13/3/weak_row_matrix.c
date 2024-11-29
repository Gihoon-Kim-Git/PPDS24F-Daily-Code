// You are given an m x n binary matrix `mat` of 1's (representing soldiers) and 0's (representing civilians).
// The soldiers are positioned in front of the civilians, meaning all the 1's appear to the left of all the 0's in each row.
//
// A row i is weaker than a row j if:
// - The number of soldiers in row i is less than the number of soldiers in row j.
// - Both rows have the same number of soldiers, and i < j.
//
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
//
// Example 1:
// Input: mat = [
//   [1, 1, 0, 0, 0],
//   [1, 1, 1, 1, 0],
//   [1, 0, 0, 0, 0],
//   [1, 1, 0, 0, 0],
//   [1, 1, 1, 1, 1]
// ], k = 3
// Output: [2, 0, 3]
//
// Example 2:
// Input: mat = [
//   [1, 0, 0, 0],
//   [1, 1, 1, 1],
//   [1, 0, 0, 0],
//   [1, 0, 0, 0]
// ], k = 2
// Output: [0, 2]
//
// Constraints:
// - 2 <= m, n <= 100
// - 1 <= k <= m
// - matrix[i][j] is either 0 or 1


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

// Custom swapping function for 2D arrays
void swap(int* a, int* b, int size) {
    for (int i = 0; i < size; i++) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

// Bubble sort function
void bubble_sort_custom(int** arr, int size) {
    /**
     * Custom bubble sort function to sort rows based on:
     * - Soldier numbers (arr[][1]) in ascending order.
     * - Row indices (arr[][0]) in ascending order for ties.
     */
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j][1] > arr[j + 1][1] || 
                (arr[j][1] == arr[j + 1][1] && arr[j][0] > arr[j + 1][0])) {
                swap(arr[j], arr[j + 1], 2); // each soldier has 2 elements
            }
        }
    }
}

// Function prototype
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    *returnSize = k; // Set the return size
    int** soldiers = (int**)malloc(matSize * sizeof(int*)); // Allocate memory for soldier count array

    for (int i = 0; i < matSize; i++) {
        soldiers[i] = (int*)malloc(2 * sizeof(int)); // Each soldier entry has two elements: index and count
        soldiers[i][0] = i; // Row index
        soldiers[i][1] = 0; // Initial soldier count
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1) {
                soldiers[i][1]++;
            }
        }
    }

    // Sort the soldiers array
    bubble_sort_custom(soldiers, matSize);

    // Prepare the result array
    int* result = (int*)malloc(k * sizeof(int)); // Allocate memory for the result
    for (int i = 0; i < k; i++) {
        result[i] = soldiers[i][0]; // Store the row indices of the k weakest rows
    }

    // Free memory for soldiers array
    for (int i = 0; i < matSize; i++) {
        free(soldiers[i]);
    }
    free(soldiers);

    return result;
}

// Example test cases
void test_kWeakestRows() {
    int mat1[5][5] = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    int* mat1Ptrs[5] = {mat1[0], mat1[1], mat1[2], mat1[3], mat1[4]};
    int matColSize1[] = {5, 5, 5, 5, 5}; // Correctly define as an array
    int returnSize1;
    int* result1 = kWeakestRows(mat1Ptrs, 5, matColSize1, 3, &returnSize1);
    printf("Test Case 1: ");
    for (int i = 0; i < returnSize1; i++) printf("%d ", result1[i]);
    printf("\n");  // Expected Output: 2 0 3
    free(result1);

    int mat2[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };
    int* mat2Ptrs[4] = {mat2[0], mat2[1], mat2[2], mat2[3]};
    int matColSize2[] = {4, 4, 4, 4}; // Correctly define as an array
    int returnSize2;
    int* result2 = kWeakestRows(mat2Ptrs, 4, matColSize2, 2, &returnSize2);
    printf("Test Case 2: ");
    for (int i = 0; i < returnSize2; i++) printf("%d ", result2[i]);
    printf("\n");  // Expected Output: 0 2
    free(result2);
}

int main() {
    test_kWeakestRows();
    return 0;
}
