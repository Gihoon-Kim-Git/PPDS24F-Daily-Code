#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<pair<int, int>> events;

    for (auto& trip : trips) {
        events.emplace_back(trip[1], trip[0]);  // Pickup event
        events.emplace_back(trip[2], -trip[0]); // Drop-off event
    }

    // Sort events by location and type
    sort(events.begin(), events.end());

    int current_passengers = 0;
    for (auto& event : events) {
        current_passengers += event.second;
        if (current_passengers > capacity)
            return false;
    }

    return true;
}

int main() {
    vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
    int capacity = 4;

    cout << (carPooling(trips, capacity) ? "True" : "False") << endl; // Output: False

    return 0;
}
