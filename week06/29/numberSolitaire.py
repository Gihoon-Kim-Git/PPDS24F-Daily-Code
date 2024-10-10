def solution(A):
    n = len(A)
    dp = [0] * n    # 현재 칸에 도달할 수 있는 최적의 경로 (최대 점수) 저장
    dp[0] = A[0]

    for i in range(1, n):    # 칸
        max_value = float('-inf')
        for k in range(1,7):   # 주사위
            if (i-k) >= 0:
                max_value = max(max_value, dp[i-k])
        dp[i] = max_value + A[i]         # 현재 도착 칸의 값 + 기존 값 중 max

    return dp[n-1]


A = [1,-2,0,9,-1,-2]
B = [-2, 5, 1]    # 4
print(solution(B))