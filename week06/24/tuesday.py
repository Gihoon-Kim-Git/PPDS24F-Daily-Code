def solution(A):
    # Length of the array A
    N = len(A)
    
    # DP array to store the maximum sum up to each index
    dp = [-float('inf')] * N
    dp[0] = A[0]  # Starting point

    # Iterate over each square
    for i in range(1, N):
        # Check up to 6 previous squares and compute the max result
        for dice_roll in range(1, 7):
            if i - dice_roll >= 0:
                dp[i] = max(dp[i], dp[i - dice_roll] + A[i])

    # Return the maximum sum that can be achieved at the last square
    return dp[-1]