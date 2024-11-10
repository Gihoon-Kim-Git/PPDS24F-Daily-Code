def solution(K, M, A):
    def valid_division(mid):
        blocks = 1
        current_sum = 0
        
        for num in A:
            current_sum += num
            if current_sum > mid:
                blocks += 1
                current_sum = num
                if blocks > K:
                    return False
        return True

    low = max(A)
    high = sum(A)
    result = high

    while low <= high:
        mid = (low + high) // 2
        if valid_division(mid):
            result = mid
            high = mid - 1
        else:
            low = mid + 1

    return result
