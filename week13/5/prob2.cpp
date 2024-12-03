#include <vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> timeline(1001, 0);
        for (auto trip : trips) {
            for (int i = trip[1]; i < trip[2]; i++) {
                timeline[i] += trip[0];
                if (timeline[i] > capacity) return false;
            }
        }
        return true;
    }
};
