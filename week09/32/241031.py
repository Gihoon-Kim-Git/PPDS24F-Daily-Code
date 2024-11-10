# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # Implement your solution here
    if not A:
        return 0

    min_price = A[0]
    max_profit = 0

    for price in A[1:]:
        profit = price - min_price

        max_profit = max(max_profit, profit)
        min_price = min(min_price, price)

    return max_profit
