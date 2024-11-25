#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    int carPooling(vector<vector<int>>& trips, int capacity) {
        int maxval = 0;
        sort(trips.begin(), trips.end(), compare); // start 기준 오름차순 -> (passengers, from, to)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
        for (int i=0; i<trips.size(); i++) {
            while (!minHeap.empty() && minHeap.top().first <=trips[i][1]) {
                maxval -= minHeap.top().second;
                minHeap.pop();
            }
            // end 기준 오름차순 -> (to, passengers)
            minHeap.push(make_pair(trips[i][2], trips[i][0]));
            maxval += trips[i][0];
            if (maxval > capacity) return false;
        }
        return true;
    }
};

int main() {
    Solution result;
    vector<vector<int>> stones = {{2,1,5},{3,3,7}};
    cout << result.carPooling(stones, 4) << endl;
    cout << result.carPooling(stones, 5) << endl;

    return 0;
}