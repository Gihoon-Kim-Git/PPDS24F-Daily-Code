// There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

// You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

// Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

 

// Example 1:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
// Output: false
// Example 2:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 5
// Output: true


// to 기준으로 하나 sorting
// from 기준으로 하나 sorting

// 둘 중에 작은거 하나 빼고, to에서 뺄때는 더하고, from에서 뺄때는 빼고
// totalPassenger가 capacity보다 크면 false


#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int maxPassenger = 0;
        int totalPassenger = 0;

        vector<vector<int>> sortedByFrom = trips;
        vector<vector<int>> sortedByTo = trips;


        sort(sortedByFrom.begin(), sortedByFrom.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });

        sort(sortedByTo.begin(), sortedByTo.end(), [](vector<int> a, vector<int> b) {
            return a[2] < b[2];
        });

        int fromIndex = 0;
        int toIndex = 0;

        while (fromIndex < trips.size()){
            if (sortedByFrom[fromIndex][1] < sortedByTo[toIndex][2]){
                totalPassenger += sortedByFrom[fromIndex][0];
                maxPassenger = max(maxPassenger, totalPassenger);
                fromIndex++;
            } else {
                totalPassenger -= sortedByTo[toIndex][0];
                toIndex++;
            }
        }

        return maxPassenger <= capacity;

        // // 다른 답안 -> 두 개의 vector로 나눌 필요가 없다 !!!
        // vector<pair<int, int>> events;
        // for (auto& trip : trips) {
        //     events.push_back({trip[1], trip[0]});
        //     events.push_back({trip[2], -trip[0]});
        // }

        // sort(events.begin(), events.end(), [](pair<int, int>& a, pair<int, int>& b) {
        //     return a.first == b.first ? a.second < b.second : a.first < b.first;
        // });

        // int total = 0;
        // for (auto& event : events) {
        //     total += event.second;
        //     if (total > capacity) {
        //         return false;
        //     }
        // }

        // return true;




        
    }
};