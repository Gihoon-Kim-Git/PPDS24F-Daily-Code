// You are given an array of integers `stones` where stones[i] is the weight of the ith stone.
//
// We are playing a game with the stones. On each turn, we choose the heaviest two stones
// and smash them together. Suppose the heaviest two stones have weights x and y with x <= y.
// The result of this smash is:
//
// - If x == y, both stones are destroyed.
// - If x != y, the stone of weight x is destroyed, and the stone of weight y has a new weight y - x.
//
// At the end of the game, there is at most one stone left.
//
// Return the weight of the last remaining stone. If there are no stones left, return 0.
//
// Example 1:
// Input: stones = [2,7,4,1,8,1]
// Output: 1
// Explanation:
// Combine 7 and 8 to get 1, array becomes [2,4,1,1,1]
// Combine 2 and 4 to get 2, array becomes [2,1,1,1]
// Combine 2 and 1 to get 1, array becomes [1,1,1]
// Combine 1 and 1 to get 0, array becomes [1]
// Return the last remaining stone: 1
//
// Example 2:
// Input: stones = [1]
// Output: 1
//
// Constraints:
// - 1 <= stones.length <= 30
// - 1 <= stones[i] <= 1000

#include <stdio.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array in descending order using selection sort
void selection_sort_descending(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        int max_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        // Swap the current element with the maximum element
        swap(&arr[i], &arr[max_idx]);
    }
}

// Function to calculate the weight of the last remaining stone
int lastStoneWeight(int* stones, int stonesSize) {
    while (stonesSize > 1) {
        // Sort the stones array in descending order
        selection_sort_descending(stones, stonesSize);

        int max_first = stones[0];
        int max_second = stones[1];

        // Remove the two heaviest stones
        // Instead of erase or push_back methods, array manipulation (shifting elements) is done manually
        for (int i = 2; i < stonesSize; i++) {
            stones[i - 2] = stones[i];
        }
        stonesSize -= 2;

        // If the heaviest stones are not equal, add the remaining weight back
        if (max_first != max_second) {
            stones[stonesSize] = max_first - max_second;
            stonesSize += 1;
        }
    }

    // Return the weight of the last remaining stone, or 0 if no stones remain
    return stonesSize == 0 ? 0 : stones[0];
}

// Example usage
int main() {
    int stones[] = {2, 7, 4, 1, 8, 1};
    int stonesSize = sizeof(stones) / sizeof(stones[0]);

    int result = lastStoneWeight(stones, stonesSize);
    printf("Last stone weight: %d\n", result); // Output: Last stone weight: 1

    return 0;
}
