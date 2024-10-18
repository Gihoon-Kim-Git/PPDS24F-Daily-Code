# min max division
def solution(K, M, A):
    def can_divide_blocks(A, K, max_block_sum):
        current_sum = 0
        blocks_count = 1
        for value in A:
            if current_sum + value > max_block_sum:
                # Start a new block
                blocks_count += 1
                current_sum = value
                if blocks_count > K:
                    return False
            else:
                current_sum += value
        return True
    
    # Binary search initialization
    lower_bound = max(A)  # The minimum possible large sum is the max element
    upper_bound = sum(A)  # The maximum possible large sum is the sum of the entire array
    
    while lower_bound <= upper_bound:
        mid = (lower_bound + upper_bound) // 2
        if can_divide_blocks(A, K, mid):
            upper_bound = mid - 1  # Try to find a smaller large sum
        else:
            lower_bound = mid + 1  # Increase the large sum

    return lower_bound