# stair의 cost가 list로 주어졌을 때 마지막 계단을 밟는 최소 cost구하기
# 단, cost를 지불하면 한 칸 / 두 칸을 더 오를 수 있음 

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # i번째 stair를 밟을때의 최소 cost
        stepCost = cost[:]
        for i in range(2, len(cost)):
            stepCost[i] += min(stepCost[i-1], stepCost[i-2])
        return min(stepCost[-2], stepCost[-1])  