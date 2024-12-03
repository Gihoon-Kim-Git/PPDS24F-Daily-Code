#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> changes(1001, 0);
        for (const auto& trip : trips) {
            changes[trip[1]] += trip[0];
            changes[trip[2]] -= trip[0];
        }

        int currentPassengers = 0;
        for (int change : changes) {
            currentPassengers += change;
            if (currentPassengers > capacity) {
                return false;
            }
        }
        return true;
    }
};