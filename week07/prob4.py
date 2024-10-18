# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(K, M, A):
    # Implement your solution here
    left = M
    right = sum(A)
    blocks = 1
    blocksum = 0
    res = right

    while blocks <= K:
        mid = (left + right) // 2
        block_cnt = 1
        for x in A:
            blocksum += x
            if blocksum > mid:
                block_cnt += 1
                if block_cnt > blocks:
                    blocks += 1
                    right = mid
                    break
                else:
                    blocksum = x
        res = mid

    return res
                    
    
         
 