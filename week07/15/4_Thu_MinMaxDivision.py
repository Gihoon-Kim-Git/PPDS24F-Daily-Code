# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(K, M, A):
    # Implement your solution here

    def can_divide(A, K, max_sum):
        count = 1
        current_sum = 0
        for num in A:
            if current_sum + num > max_sum:
                count += 1
                current_sum = num
                if count > K:
                    return False
            else:
                current_sum += num
        return True
        
    low = max(A)
    high = sum(A)

    while low <= high:
        mid = (low + high) // 2
        if can_divide(A, K, mid):
            high = mid - 1
        else:
            low = mid + 1
    
    return low