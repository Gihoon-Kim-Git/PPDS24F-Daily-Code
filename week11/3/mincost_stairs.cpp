#include <vector>
#include <algorithm> // For std::min

using namespace std;

/*
 * Class: Solution
 * ----------------
 *  Provides a method to calculate the minimum cost to reach the top of a staircase.
 */
class Solution {
public:
    /*
     * Function: minCostClimbingStairs
     * -------------------------------
     *  Calculates the minimum cost to reach the top of a staircase.
     *
     *  Problem Explanation:
     *  - You can start from step 0 or step 1.
     *  - You can climb either one or two steps at a time.
     *  - You pay the cost of the step you are on before climbing.
     * 
     *  Approach:
     *  - Use dynamic programming (DP) to calculate the minimum cost to reach each step.
     *  - The DP formula is:
     *      dp[i] = cost[i] + min(dp[i-1], dp[i-2])
     *    where dp[i] represents the minimum cost to reach step i.
     *  - The answer is the minimum of dp[cost.size() - 1] and dp[cost.size() - 2].
     *
     *  Input:
     *    - cost: A vector where cost[i] is the cost of the i-th step.
     *
     *  Output:
     *    - The minimum cost to reach the top of the staircase.
     */
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // Base cases for arrays of size 2
        if (n == 2) {
            return min(cost[0], cost[1]);
        }

        // Initialize the first two steps
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Fill the DP array for subsequent steps
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // The result is the minimum cost to reach the top (beyond the last step)
        return min(dp[n - 1], dp[n - 2]);
    }
};