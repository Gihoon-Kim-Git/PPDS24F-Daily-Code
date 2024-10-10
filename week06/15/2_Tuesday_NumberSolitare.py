def solution(A):
    # Implement your solution here
    dp = [-float('inf')]*(len(A))
    dp[0] = A[0]
    for i in range(len(A)):
        for d in range(1,7):
            if i + d < len(A):
                dp[i+d] = max(dp[i+d], A[i+d] + dp[i])
    return dp[len(A)-1]

A = [1, -2, 0, 9, -1, -2]
print(solution(A))
