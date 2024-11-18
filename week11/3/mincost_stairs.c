#include <stdio.h>

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
 *  - The answer is the minimum of dp[costSize - 1] and dp[costSize - 2].
 *
 *  Input:
 *    - cost: An array where cost[i] is the cost of the i-th step.
 *    - costSize: The size of the cost array.
 *
 *  Output:
 *    - The minimum cost to reach the top of the staircase.
 */
int minCostClimbingStairs(int* cost, int costSize) {
    // Base cases for arrays of size 2
    if (costSize == 2) {
        return (cost[0] < cost[1]) ? cost[0] : cost[1];
    }

    // Allocate an array for DP and initialize the first two steps
    int dp[costSize];
    dp[0] = cost[0];
    dp[1] = cost[1];

    // Fill the DP array for subsequent steps
    for (int i = 2; i < costSize; i++) {
        dp[i] = cost[i] + (dp[i - 1] < dp[i - 2] ? dp[i - 1] : dp[i - 2]);
    }

    // The result is the minimum cost to reach the top (beyond the last step)
    return (dp[costSize - 1] < dp[costSize - 2]) ? dp[costSize - 1] : dp[costSize - 2];
}