from collections import List 

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:

        if not cost: 
            return 0
        
        dp = [0] * len(cost) # memorize min cost at i-th step

        dp[0] = cost[0]
       
        if len(cost) >= 2:
            dp[1] = cost[1]
        # dp[2] = cost[2] + min(dp[0], dp[1])

        for i in range(2, len(cost)):
            dp[i] = cost[i] + min(dp[i-1], dp[i-2])
        
        return min(dp[-1], dp[-2])