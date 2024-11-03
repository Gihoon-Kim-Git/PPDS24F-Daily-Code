def solution(A):
    if len(A) < 2:
        return 0
    
    min_price = A[0]
    max_profit = 0
    
    for price in A[1:]:
        min_price = min(min_price, price)
        profit = price - min_price
        max_profit = max(max_profit, profit)
    
    return max_profit