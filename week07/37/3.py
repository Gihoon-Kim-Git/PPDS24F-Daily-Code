def solution(A):
    A.sort()
    
    max_product_end = A[-1] * A[-2] * A[-3]
    max_product_start = A[0] * A[1] * A[-1]
    
    result = max(max_product_end, max_product_start)
    
    return result
