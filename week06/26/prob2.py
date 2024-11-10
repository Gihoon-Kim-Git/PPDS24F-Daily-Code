def solution(A):
    # Implement your solution here
    dp = [0 for _ in A]
    dp[0] = A[0]

    for i in range(1, min(len(A), 6)):
        dp[i] = A[i] + max(dp[:i])
    for i in range(6, len(A)):
        dp[i] = A[i] + max(dp[i-6:i])

    return dp[-1]