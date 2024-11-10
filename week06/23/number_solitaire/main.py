def solution(A):
    N = len(A)
    
    # dp array to store the maximum sum at each square
    dp = [-float('inf')] * N
    dp[0] = A[0]  # The game starts at square 0
    
    # Iterate through the board to fill the dp array
    for i in range(1, N):
        # Look at up to 6 previous squares to get the max score
        dp[i] = max(dp[max(i - 6, 0):i]) + A[i]
    
    return dp[N - 1]

# Example usage
A = [1, -2, 0, 9, -1, -2]
print(solution(A))  # Output: 8
