// You are given the integer capacity and an array `trips` where trips[i] = {numPassengers, from, to}
// indicates that the ith trip has `numPassengers` passengers, and the locations to pick them up
// and drop them off are `from` and `to`, respectively.
//
// The vehicle only drives east (i.e., it cannot turn around and drive west).
//
// Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
//
// Example 1:
// Input: trips = {{2, 1, 5}, {3, 3, 7}}, capacity = 4
// Output: false
//
// Example 2:
// Input: trips = {{2, 1, 5}, {3, 3, 7}}, capacity = 5
// Output: true
//
// Constraints:
// - 1 <= trips.length <= 1000
// - trips[i].length == 3
// - 1 <= numPassengers <= 100
// - 0 <= from < to <= 1000
// - 1 <= capacity <= 10^5

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Custom swapping function for 2D arrays
void swap(int* a, int* b, int size) {
    for (int i = 0; i < size; i++) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

// Bubble sort function to sort events
void bubble_sort(int** arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Sort by location first; if equal, sort by passenger change
            if (arr[j][0] > arr[j + 1][0] || 
                (arr[j][0] == arr[j + 1][0] && arr[j][1] > arr[j + 1][1])) {
                swap(arr[j], arr[j + 1], 2); // Each event has two elements
            }
        }
    }
}

// Function to check if car pooling is possible
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    // Edge case: no trips
    if (tripsSize == 0) {
        return true;
    }

    // Step 1: Extract events
    int eventsSize = tripsSize * 2;
    int** events = (int**)malloc(eventsSize * sizeof(int*));
    for (int i = 0; i < eventsSize; i++) {
        events[i] = (int*)malloc(2 * sizeof(int)); // Each event has 2 elements
    }

    int index = 0;
    for (int i = 0; i < tripsSize; i++) {
        int numPassengers = trips[i][0];
        int pickUp = trips[i][1];
        int dropOff = trips[i][2];

        // Add pickup and drop-off events
        events[index][0] = pickUp;
        events[index][1] = numPassengers;
        index++;

        events[index][0] = dropOff;
        events[index][1] = -numPassengers;
        index++;
    }

    // Step 2: Sort events using bubble sort
    bubble_sort(events, eventsSize);

    // Step 3: Simulate passenger flow
    int currentPassengers = 0;
    for (int i = 0; i < eventsSize; i++) {
        currentPassengers += events[i][1];
        if (currentPassengers > capacity) {
            // Free memory before returning
            for (int j = 0; j < eventsSize; j++) {
                free(events[j]);
            }
            free(events);
            return false;
        }
    }

    // Free memory before returning
    for (int i = 0; i < eventsSize; i++) {
        free(events[i]);
    }
    free(events);
    return true;
}

// Example test cases
void test_carPooling() {
    // Test Case 1
    int trips1[][3] = {{2, 1, 5}, {3, 3, 7}};
    int* trips1Ptrs[] = {trips1[0], trips1[1]};
    int tripsColSize1[] = {3, 3};
    printf("%s\n", carPooling(trips1Ptrs, 2, tripsColSize1, 4) ? "True" : "False"); // Output: False

    // Test Case 2
    int trips2[][3] = {{2, 1, 5}, {3, 3, 7}};
    int* trips2Ptrs[] = {trips2[0], trips2[1]};
    int tripsColSize2[] = {3, 3};
    printf("%s\n", carPooling(trips2Ptrs, 2, tripsColSize2, 5) ? "True" : "False"); // Output: True

    // Test Case 3
    int trips3[][3] = {{2, 2, 5}, {3, 5, 7}};
    int* trips3Ptrs[] = {trips3[0], trips3[1]};
    int tripsColSize3[] = {3, 3};
    printf("%s\n", carPooling(trips3Ptrs, 2, tripsColSize3, 4) ? "True" : "False"); // Output: True

    // Test Case 4
    int trips4[][3] = {{3, 2, 8}, {4, 4, 6}, {10, 1, 3}};
    int* trips4Ptrs[] = {trips4[0], trips4[1], trips4[2]};
    int tripsColSize4[] = {3, 3, 3};
    printf("%s\n", carPooling(trips4Ptrs, 3, tripsColSize4, 11) ? "True" : "False"); // Output: False
}

int main() {
    test_carPooling();
    return 0;
}