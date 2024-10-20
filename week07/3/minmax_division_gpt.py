"""
Problem: Minimize the Large Sum of K Blocks

You are given integers K (number of blocks), M (maximum value in the array), 
and a non-empty array A of N integers. The goal is to divide the array into exactly 
K contiguous blocks such that the largest sum of any block (large sum) is minimized.

For example:
Given K = 3, M = 5, and A = [2, 1, 5, 1, 2, 2, 2], the possible large sums include:
- [2, 1], [5, 1], [2, 2, 2] → large sum = 6
- [2, 1, 5], [], [1, 2, 2, 2] → large sum = 8
- The goal is to minimize this large sum.

Constraints:
- N, K are between 1 and 100,000.
- M is between 0 and 10,000.
- Each element in A is between 0 and M.

Approach:
- Use **binary search** on the possible range of large sums. The lower bound of the large sum is 
  the maximum element in the array (as no block can have a sum smaller than the largest element), 
  and the upper bound is the sum of all elements in the array.
- For a given "mid" value in binary search, determine if the array can be divided into K or fewer blocks 
  such that no block sum exceeds "mid".
- Adjust the binary search range based on whether the current mid value is feasible or not.

Time Complexity: O(N * log(S)), where S is the sum of all elements in the array.
Space Complexity: O(1) as we use only a few extra variables.
"""

# Function to check if it's possible to divide the array into K or fewer blocks 
# such that no block has a sum greater than `max_sum`.
def can_divide(A, K, max_sum):
    current_sum = 0  # Current sum of the block
    blocks = 1  # Start with one block

    # Traverse the array and try to form blocks with sum <= max_sum
    for num in A:
        # If adding the current element exceeds max_sum, start a new block
        if current_sum + num > max_sum:
            blocks += 1  # Increment the number of blocks
            current_sum = num  # Start the new block with the current element
        else:
            current_sum += num  # Add the current element to the current block

        # If the number of blocks exceeds K, return False (mid is too small)
        if blocks > K:
            return False

    return True  # Return True if it is possible to divide into K or fewer blocks

# Function to find the minimal large sum using binary search
def solution(K, M, A):
    # Initialize the search range
    low = max(A)  # Minimum possible large sum (at least the max element)
    high = sum(A)  # Maximum possible large sum (sum of all elements)

    # Perform binary search to find the minimal large sum
    while low <= high:
        mid = (low + high) // 2  # Try the middle value as a candidate for large sum

        if can_divide(A, K, mid):
            # If it's possible to divide with this large sum, try a smaller one
            high = mid - 1
        else:
            # If not possible, try a larger large sum
            low = mid + 1

    # The smallest feasible large sum is found when low > high
    return low

# Example Usage
K = 3
M = 5
A = [2, 1, 5, 1, 2, 2, 2]
print(solution(K, M, A))  # Output: 6
