# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # Implement your solution here
    #dynamic programming
    n = len(A)
    dp = [0] * n
    dp[0] = A[0]
    for i in range(1,n):
        temp = dp[i-1] # -1 from current
        for j in range(2,7): # -2~-6 from current
            if i-j >= 0 :
                temp = max(temp,dp[i-j])
            else : break
        dp[i]= temp + A[i]

    return dp[-1]

# Time O(N)