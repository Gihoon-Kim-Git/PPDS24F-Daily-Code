#include <stdio.h>
#include <stdlib.h>

// Function to flip the array up to index `k`
void flip(int *arr, int k)
{
    int start = 0, end = k;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to find the index of the largest element in the array up to index `n`
int findMaxIndex(int *arr, int n)
{
    int maxIndex = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Main Pancake Sorting function
int *pancakeSort(int *arr, int arrSize, int *returnSize)
{
    int *result = (int *)malloc(arrSize * 2 * sizeof(int)); // Allocate memory for result
    int resultIndex = 0;

    for (int size = arrSize; size > 1; size--)
    {
        // Find the index of the largest unsorted element
        int maxIndex = findMaxIndex(arr, size - 1);

        // Flip to bring the largest element to the front
        if (maxIndex != 0)
        {
            result[resultIndex++] = maxIndex + 1; // Store the flip size
            flip(arr, maxIndex);
        }

        // Flip to bring the largest element to its correct position
        result[resultIndex++] = size; // Store the flip size
        flip(arr, size - 1);
    }

    *returnSize = resultIndex; // Update the size of the result array
    return result;
}

// Helper function to print an array
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Test the function
int main()
{
    int arr[] = {3, 2, 4, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int returnSize;

    printf("Original array: ");
    printArray(arr, arrSize);

    int *result = pancakeSort(arr, arrSize, &returnSize);

    printf("Sorted array: ");
    printArray(arr, arrSize);

    printf("Pancake flips: ");
    printArray(result, returnSize);

    free(result); // Free the allocated memory
    return 0;
}
