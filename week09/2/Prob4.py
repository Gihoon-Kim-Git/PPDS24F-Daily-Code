# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # Implement your solution here
    if not A:
        return 0

    result = 0
    min_price = A[0]  #initial value of min price
    for i in range(1, len(A)):
        if min_price > A[i]:
            min_price = A[i]
        elif A[i] - min_price > result:
            result = A[i] - min_price
    return result


    

