def solution(A):
    if not A:
        return 0
    
    max_profit = 0
    min_price = A[0]

    for price in A:
        potential_profit = price - min_price
        max_profit = max(max_profit, potential_profit)
        min_price = min(min_price, price)

    return max_profit