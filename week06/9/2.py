def solution(A):
    N = len(A)
    
    dp = [-10001] * N
    dp[0] = A[0]
    
    for i in range(1, N):
        dp[i] = A[i] + max(dp[max(0, i - 6):i])
    
    return dp[N - 1]

if __name__ == '__main__':
    A = [1,-2,0,9,-1,-2]
    print(solution(A))
    pass






"""

A = [1,-2,0,9,-1,-2]

dp[2] = [0, 9, -1, -2, 0, 0]
dp[3] = []


"""


