class Solution:
    def minCostClimbingStairs(self, cost: list[int]) -> int:
        dp = [0] * len(cost)
        dp[0] = cost[0]
        dp[1] = cost[1]
        for i in range(2,len(cost)):
            dp[i] = cost[i] + min(dp[i-2], dp[i-1])
        
        return min(dp[len(cost)-1], dp[len(cost)-2])