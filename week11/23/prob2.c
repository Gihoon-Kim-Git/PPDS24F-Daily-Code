#include <stdio.h>

int minCostClimbingStairs(int* cost, int costSize) {
    if (costSize == 0) return 0;
    if (costSize == 1) return cost[0];
    
    int dp[costSize];
    dp[0] = cost[0];
    if (costSize >= 2) {
        dp[1] = cost[1];
    }
    
    for (int i = 2; i < costSize; i++) {
        dp[i] = cost[i] + (dp[i-1] < dp[i-2] ? dp[i-1] : dp[i-2]);
    }
    
    return dp[costSize-1] < dp[costSize-2] ? dp[costSize-1] : dp[costSize-2];
}

// Driver Code
int main() {
    int cost[] = {10, 15, 20};
    int costSize = sizeof(cost) / sizeof(cost[0]);
    
    int result = minCostClimbingStairs(cost, costSize);
    printf("Minimum cost to climb stairs: %d\n", result);
    
    return 0;
}
