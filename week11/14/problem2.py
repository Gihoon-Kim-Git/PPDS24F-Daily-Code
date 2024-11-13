# week 11

# Tuesday. [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/description/)

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        for i in range(2,len(cost)):
            cost[i]+=min(cost[i-1],cost[i-2])
        print(cost)
        return min(cost[-1],cost[-2])