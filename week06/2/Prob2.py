# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # Implement your solution here
    N = len(A)
    
    # 각 칸에 도달할 수 있는 최대값을 저장하는 list를 생성
    dp = []
    
    # initial value
    dp.append(A[0])
    
    #1번 칸부터 max값을 찾아갈 필요
    for i in range(1, N):
        dp.append(A[i] + max(dp[max(0, i-6):i]))
    
    return dp[N-1]