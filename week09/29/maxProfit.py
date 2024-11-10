# A[j] - A[i] (j>=i) 최대값 찾기
# Optimize to O(N)

def solution(A):
    if not A: return 0

    max_profit = 0
    min_price = A[0]

    for price in A[1:]:
        profit = price - min_price
        max_profit = max(max_profit, profit)
        min_price = min(min_price, price)
    
    return max_profit 

    

A = [23171, 21011, 21123, 21366, 21013, 21367]
print(solution(A))

