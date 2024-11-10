# week 07

## Wednesday. [Max Product of Three](https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/)

def solution(A):
    # write your code in Python 3.6
    A.sort()
    if A[-1] < 0:
        prod = (A[-1] * A[-2] * A[-3])
    elif A[0] * A[1] > A[-2] * A[-3]:
        prod = (A[-1] * A[1] * A[0])       
    else:
        prod = (A[-1] * A[-2] * A[-3])
    return prod