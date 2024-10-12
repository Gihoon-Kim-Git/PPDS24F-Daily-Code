# Function to find the subset of maximal sum in an array where the distance between consecutive elements is at most 6.
#
# A game for one player is played on a board with N squares (0 to N-1). A non-empty array A of N integers contains
# the numbers written on the squares.
#
# You throw a six-sided die and move the pebble from the current square to square i+K, if K is valid (1 <= K <= 6).
# The game ends when the pebble reaches the last square (N-1), and the result is the sum of the numbers on all marked squares.
#
# Examples:
# - Given A = [1, -2, 0, 9, -1, -2], the function should return 8.
#   One possible sequence of moves: 0 -> 3 -> 5.
#
# Assumptions:
# - N is an integer within the range [2..100,000];
# - Each element of array A is an integer within the range [-10,000..10,000].
def solution(A):
    # start at index 0
    # move from index i to index i+K (i+K is valid index within the array)
    # goal: reach last square N-1, maximising the sum of the numbers on all squares

    N = len(A)

    # DP array: store maximum sum to reach each square
    # dp[i]: best possible sum you can collect when you reach square i
    dp = [-float('inf')]*N
    dp[0] = A[0] # initialization

    for i in range(1, N):
        # check all jumps from the last 1~6 squares
        for K in range(1, 7):
            # dp[i] = max(dp[i-1], dp[i-2], ..., dp[i-6]) + A[i]
            if i-K >= 0: # check whether jumping K steps back from square i is valid
                # best sum of [previous squares + current square]
                dp[i] = max(dp[i], dp[i-K] + A[i])

    # maximum sum achievable to reach the last square (N-1)
    return dp[N - 1]


def test_numbersolitaire():
    # Test case 1: Example from the problem statement
    assert solution([1, -2, 0, 9, -1, -2]) == 8, "Test case 1 failed"
    
    # Test case 2: Single element (only 1 possible move)
    assert solution([5]) == 5, "Test case 2 failed"
    
    # Test case 3: All negative numbers
    assert solution([-1, -2, -3, -4, -5, -6]) == -7, "Test case 3 failed"
    
    # Test case 4: All positive numbers
    assert solution([1, 2, 3, 4, 5, 6]) == 21, "Test case 4 failed"
    
    # Test case 5: Mixed values with gaps
    assert solution([1, -2, 9, 5, -6, 2, 10, -1]) == 26, "Test case 5 failed"
    
    print("All NumberSolitaire test cases passed.")

# Run the test
test_numbersolitaire()
