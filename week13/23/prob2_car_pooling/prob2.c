#include <stdio.h>
#include <stdbool.h>

#define MAX_DISTANCE 1001

bool carPooling(int trips[][3], int tripsSize, int capacity) {
    int timeline[MAX_DISTANCE] = {0};

    for (int i = 0; i < tripsSize; ++i) {
        int numPassengers = trips[i][0];
        int from = trips[i][1];
        int to = trips[i][2];

        timeline[from] += numPassengers;
        timeline[to] -= numPassengers;
    }

    int current_passengers = 0;
    for (int i = 0; i < MAX_DISTANCE; ++i) {
        current_passengers += timeline[i];
        if (current_passengers > capacity) {
            return false;
        }
    }
    return true;
}

int main() {
    int trips1[][3] = {{2, 1, 5}, {3, 3, 7}};
    printf("%d\n", carPooling(trips1, 2, 4));  // Output: 0 (False)
    printf("%d\n", carPooling(trips1, 2, 5));  // Output: 1 (True)
    return 0;
}
