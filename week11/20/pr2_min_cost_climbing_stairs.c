int min(int a, int b){
    return a <= b ? a : b;
}
// 아래에서 위로
int minCostClimbingStairs(int* cost, int costSize) {
    int dp[costSize];
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i=2;i<costSize;i++){
        dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
    }
    return min(dp[costSize-1],dp[costSize-2]);
}