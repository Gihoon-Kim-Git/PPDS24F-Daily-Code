from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        mincost = [0] * n 
        mincost[1] = min(cost[0], cost[1])
        for i in range(2, n):
            mincost[i] = min(mincost[i-1] + cost[i], mincost[i-2] + cost[i-1])
        return mincost[n-1]