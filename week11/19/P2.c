#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int minCostClimbingStairs(int* cost, int costSize) {
    int* dp = (int*)malloc(sizeof(int) * costSize);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i=2; i<costSize; i++) dp[i] = min(dp[i-1], dp[i-2]) +cost[i];
    return min(dp[costSize-1], dp[costSize-2]);
}

int main() {
    int cost1[] = {10,15,20};
    printf("%d\n", minCostClimbingStairs(cost1, 3));
    int cost2[] = {1,100,1,1,1,100,1,1,100,1};
    printf("%d\n", minCostClimbingStairs(cost2, 10));
    
    return 0;
}