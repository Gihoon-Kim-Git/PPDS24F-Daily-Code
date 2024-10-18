def solution(A):
    # Implement your solution here
    A.sort()

    result = A[-1] * A[-2] * A[-3]

    sub = A[0] * A[1] * A[-1]

    if (sub > result):
        result = sub
    return result
