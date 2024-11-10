# Maximum Slice Problem
# Max Profit - Given a list of stock prices, find the maximum profit

def solution(A):
    max_profit = 0
    min_price = float('inf')
    for price in A:
        min_price = min(min_price, price)
        max_profit = max(max_profit, price - min_price)
    return max_profit

