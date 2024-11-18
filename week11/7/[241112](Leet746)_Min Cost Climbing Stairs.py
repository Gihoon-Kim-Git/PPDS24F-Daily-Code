"""문제
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor."""

"""아이디어
    n이 len(cost)일때
    최종구해야할 값 : min(dp[n-2], dp[n-1]) 
    - base case : 0 또는 1
    - recursive case : dp[i] = cost[i] + min(dp[i-1], dp[i-2])
"""

"""수도코드
1. dpT을 하나 만든다. cost와 같은 크기로.
    (Bottomup의 경우 cost를 그대로 쓰면서 update해도 되지만, 따로 하나 만드는 게 안전. )

2. 필요한 초기세팅
    n = len(cost)
    dpT[0] = cost[0]
    dpT[1] = cost[1]
    
3. 나머지 index (2 ~ n-1)에 대해서는 아래 점화식을 활용해 값을 update
    for i in range(2, n):
        dpT[i] = cost[i] + min(dpT[i-1], dpT[i-2])

4. 결과 반환
    RETURN min(dpT[n-2], dpT[n-1])
"""

class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        n = len(cost)
        dpT = [0 for _ in range(n)]
        
        dpT[0] = cost[0]
        dpT[1] = cost[1]
        
        for i in range(2,n):
            dpT[i] = cost[i] + min(dpT[i-1], dpT[i-2])
        
        return min(dpT[n-2], dpT[n-1])


