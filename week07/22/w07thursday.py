def solution(K, M, A):
    def can_divide(A, K, max_block_sum):
        block_sum = 0
        blocks = 1
        for num in A:
            if block_sum + num > max_block_sum:
                blocks += 1
                block_sum = num
                if blocks > K:
                    return False
            else:
                block_sum += num
        return True

    left = max(A)
    right = sum(A)
    result = right

    while left <= right:
        mid = (left + right) // 2
        if can_divide(A, K, mid):
            result = mid
            right = mid - 1
        else:
            left = mid + 1

    return result