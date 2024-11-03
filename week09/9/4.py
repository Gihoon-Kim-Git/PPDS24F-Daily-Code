
def solution(A : list) -> int:
    m = 0
    for i in range(len(A)):
        for j in range(i, len(A)):
            if A[j] - A[i] > m:
                m = A[j] - A[i]
    return m