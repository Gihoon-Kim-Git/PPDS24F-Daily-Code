def minCostClimbingStairs(cost):

    n = len(cost)

    if n==1: return cost[0]   # 1개 밖에 없으면 그 돈 내면 끝

    dp = [0] * n     # minimum cost to reach step i
    dp[0] = cost[0]
    dp[1] = cost[1]

    for i in range(2,n):
        dp[i] = cost[i] + min(dp[i-1], dp[i-2])   # 한 칸 전에서 오는 게 더 minimum인지 두 칸 전에서 오는 게 더 minimum인지

    return min(dp[n-1], dp[n-2])