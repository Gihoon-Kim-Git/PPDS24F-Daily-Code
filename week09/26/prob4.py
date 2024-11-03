def solution(A):
    # Implement your solution here
    if len(A) == 0:
        return 0
    min_price = A[0]
    max_profit = 0

    for price in A[1:]:
        min_price = min(min_price, price)
        max_profit = max(price - min_price, max_profit)
    
    return max_profit