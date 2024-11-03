def solution(A):
    # Implement your solution here
    if not A : return 0
    
    profit = 0
    min_val = A[0]
    for x in A :
        profit = max(profit,x-min_val)
        min_val = min(min_val,x)
    
    return profit