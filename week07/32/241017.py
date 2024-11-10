def can_divide(A, K, max_sum):
    current_sum = 0
    blocks = 1

    for num in A:
        if current_sum + num > max_sum:
            blocks += 1
            current_sum = num
            if blocks > K:
                return False
        else:
            current_sum += num

    return True

def solution(K, M, A):
    left = max(A)
    right = sum(A)

    while left < right:
        mid = (left + right) // 2

        if can_divide(A, K, mid):
            right = mid
        else:
            left = mid + 1

    return left