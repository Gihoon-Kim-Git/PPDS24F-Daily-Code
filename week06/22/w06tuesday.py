def solution(A):
    N = len(A)
    dp = [float('-inf')] * N
    dp[0] = A[0]

    for i in range(1, N):
        dp[i] = max(dp[i - k] for k in range(1, 7) if i - k >= 0) + A[i]

    return dp[-1]
