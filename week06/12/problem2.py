def solution(A):
    n = len(A)
    dp = [-float('inf')] * n
    dp[0] = A[0]  

    for i in range(n):
        if dp[i] == -float('inf'):
            continue
        
        for k in range(1, 7):
            j = i + k
            if j < n: 
                dp[j] = max(dp[j], dp[i] + A[j])

    return dp[n - 1] 