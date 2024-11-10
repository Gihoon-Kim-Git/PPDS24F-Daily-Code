def can_divide(A, K, max_block_sum):
    block_count = 1
    current_block_sum = 0
    
    for num in A:
        if current_block_sum + num > max_block_sum:
            # Start a new block
            block_count += 1
            current_block_sum = num
            if block_count > K:
                return False
        else:
            current_block_sum += num
    
    return True

def minimize_large_sum(K, M, A):
    # Binary search boundaries
    left = max(A)  # Minimum possible large sum is the max element
    right = sum(A)  # Maximum possible large sum is the sum of the array
    
    while left <= right:
        mid = (left + right) // 2
        if can_divide(A, K, mid):
            right = mid - 1  # Try a smaller large sum
        else:
            left = mid + 1  # Increase the large sum
    
    return left

# Example usage
K = 3
M = 5
A = [2, 1, 5, 1, 2, 2, 2]
result = minimize_large_sum(K, M, A)
print("Minimal large sum:", result)
