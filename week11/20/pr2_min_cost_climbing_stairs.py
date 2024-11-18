# temp = [0]*10
# print(temp)
# print(temp[2])
# test = [3,4,5,6]
# for i in range(3,-1,-1):
#     print(test[i])
class Solution:
    def minCostClimbingStairs(self, cost: list[int]) -> int:
        dp = [0]*(len(cost)+2)
        for i in range(len(cost)-1,-1,-1):
            dp[i] = cost[i] + min(dp[i+1],dp[i+2])
        return min(dp[0],dp[1])