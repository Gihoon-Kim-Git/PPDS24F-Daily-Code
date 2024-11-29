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

#include <vector>
#include <iostream>
#include <cassert>
using namespace std; // std::vector

class Solution {
public:

    // custom swapping function
    void swap(vector<int>& a, vector<int>& b) {
        std::vector<int> temp = a;
        a = b;
        b = temp;
    }

    void bubble_sort(vector<vector<int>>& arr) {
        // Custom bubble sort function to sort events. (ascending order)
        // Sort by location first, and if locations are the same, sort by passenger change.
        int n = arr.size();
        for (int i=0 ; i < n ; i++) {
            for (int j=0 ; j < n-i-1 ; j++) {
                // Compare current event and the next event
                // Sort by location; if equal, sort by passenger change
                if ((arr[j][0] > arr[j+1][0]) || ((arr[j][0] == arr[j + 1][0]) && (arr[j][1] > arr[j + 1][1]))) {
                    // Swap arr[j] and arr[j + 1]
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Skeleton code: implement logic here
        if (trips.size() == 0) {
            return true; // no passengers exist
        }
        
        // Extract Events:
        // For each trip [numPassengers, from, to], create two events:
        // Pickup at from (+numPassengers).
        // Drop-off at to (-numPassengers).
        vector<vector<int>> events;
        for (const auto& trip : trips) {
            int numPassengers = trip[0];
            int pickUp = trip[1];
            int dropOff = trip[2];

            events.push_back({pickUp, numPassengers});
            events.push_back({dropOff, -numPassengers});
        }

        // Sort Events:
        // Sort by location, and if two events are at the same location, prioritize drop-off over pickup.
        bubble_sort(events);

        // Simulate Passenger Flow:
        // Traverse the sorted events, maintain a running total of passengers, and check if it exceeds the capacity.
        int curr = 0; // tracking the number of current passengers
        for (const auto& event : events) {
            int location = event[0];
            int passengerChange = event[1];

            curr += passengerChange;

            if (curr > capacity) {
                return false;
            }
        }
        // If all events processed without exceeding capacity, return true
        return true;
    }
};

// Example test cases
void test_carPooling() {
    Solution solution;
    vector<vector<int>> trips1 = {{2, 1, 5}, {3, 3, 7}};
    assert(solution.carPooling(trips1, 4) == false); // Test Case 1

    vector<vector<int>> trips2 = {{2, 1, 5}, {3, 3, 7}};
    assert(solution.carPooling(trips2, 5) == true); // Test Case 2

    vector<vector<int>> trips3 = {{2, 2, 5}, {3, 5, 7}};
    assert(solution.carPooling(trips3, 4) == true); // Test Case 3

    vector<vector<int>> trips4 = {{3, 2, 8}, {4, 4, 6}, {10, 1, 3}};
    assert(solution.carPooling(trips4, 11) == false); // Test Case 4

    cout << "All Test Cases Passed!" << endl;
}

// Uncomment to test
int main() {
    test_carPooling();
    return 0;
}