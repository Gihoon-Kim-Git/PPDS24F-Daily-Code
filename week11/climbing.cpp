#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if (size==2) {
            return min(cost[0], cost[1]);
        }
        vector<int> result(size, 0);
        result[0] = cost[0]; result[1] = cost[1];
        for (int i=2; i<size; ++i) {
            result[i] = min(result[i-2], result[i-1]) + cost[i];
        }
        
        return min(result[size-2], result[size-1]);
    }
};

int main(void) {
    Solution sol;
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int result = sol.minCostClimbingStairs(cost);
    cout << result << endl;
    return 1;
}