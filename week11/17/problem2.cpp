// 746. Min Cost Climbing Stairs
// Easy
// Topics
// Companies
// Hint
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.


#include <vector>
using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        // dp로 풀어보자 ...
        // 0에서 시작할 수도 있고, 1에서 시작할 수도 있음.

        int n = cost.size();
        vector<int> dp(n+1, 0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i <= n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);

        
    }
};