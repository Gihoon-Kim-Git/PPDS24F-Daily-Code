from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        climbcost = []
        N = len(cost)
        # base case
        climbcost.append(cost[0])
        climbcost.append(cost[1])
        if N < 3:
            return min(climbcost)
        else:

            i = 2
            while N-1 > i:
                climbcost.append(min(climbcost[i-1], climbcost[i-2])+cost[i])
                i += 1

            return min(climbcost[-1], climbcost[-2]+cost[-1])


