def solution(A):
    if not A:
        return 0
    dp = [0] * len(A)
    minvalue = A[0]
    for i in range(1, len(A)):
        minvalue = min(minvalue, A[i])
        dp[i] = max(A[i]-minvalue, dp[i-1])
    return dp[-1]

if __name__ == "__main__":
    A = [23171, 21011, 21123, 21366, 21013, 21367]
    
    print(solution(A))