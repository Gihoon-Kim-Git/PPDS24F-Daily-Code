#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int mincost[n];
        for (int i = 0; i < n; i++){
            mincost[i] = 0;
        }
        mincost[1] = min(cost[0], cost[1]);
        for(int i=2; i<n; i++) {
            mincost[i] = min(mincost[i-2] + cost[i-1], mincost[i-1] + cost[i]);
        }
        return mincost[n-1];
    }
};