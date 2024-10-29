def solution(A):
    if len(A) == 3:
        return A[0] * A[1] * A[2]
    
    A.sort()
    
    a = A[-1] * A[-2] * A[-3]  
    b = A[0] * A[1] * A[-1]    
    
    return a if a > b else b
