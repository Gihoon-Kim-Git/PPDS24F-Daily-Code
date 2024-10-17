#include <stdio.h>
#include <stdlib.h>

int canDivide(int A[], int N, int K, int max_block_sum) {
    int blocks_used = 1;  // We need at least one block
    int current_block_sum = 0;

    for (int i = 0; i < N; i++) {
        // If adding A[i] to the current block exceeds the max_block_sum, create a new block
        if (current_block_sum + A[i] > max_block_sum) {
            blocks_used++;
            current_block_sum = A[i];  // Start new block with A[i]
            if (blocks_used > K) {
                return 0;  // More than K blocks needed
            }
        } else {
            current_block_sum += A[i];  // Add to the current block
        }
    }
    return 1;  // It's possible to split the array into K or fewer blocks
}

// Main solution function
int solution(int K, int M, int A[], int N) {
    int max_element = 0;
    int total_sum = 0;

    // Calculate the maximum element and the sum of the array
    for (int i = 0; i < N; i++) {
        if (A[i] > max_element) {
            max_element = A[i];
        }
        total_sum += A[i];
    }

    // Binary search for the minimal large sum
    int low = max_element;
    int high = total_sum;
    int result = total_sum;

    while (low <= high) {
        int mid = (low + high) / 2;
        // Check if we can divide the array with `mid` as the max large sum
        if (canDivide(A, N, K, mid)) {
            result = mid;  // This is a valid solution, try for a smaller one
            high = mid - 1;
        } else {
            low = mid + 1;  // This is too small, try a larger value
        }
    }

    return result;
}
