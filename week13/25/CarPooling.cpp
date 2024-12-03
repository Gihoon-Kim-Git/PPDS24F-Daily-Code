#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int max_ = INT_MIN;
        for (int i=0; i<trips.size(); ++i) {
            if (trips[i][2] > max_) {max_ = trips[i][2];} 
        }

        vector<int> result(max_+1, 0);
        for (int i=0; i<trips.size(); ++i) {
            for (int j=trips[i][1]; j<trips[i][2]; ++j) {
                result[j] += trips[i][0];
                if (result[j] > capacity) {return false;}
            }
        }
        return true;
    }
};

int main(void) {
    Solution sol;
    vector<vector<int>> trips = {{2,1,5}, {3,3,7}};
    int capacity = 4;
    cout << sol.carPooling(trips, capacity) << endl;
    priority_queue<int, vector<int>, greater<int>> pq;
    return 0;
}