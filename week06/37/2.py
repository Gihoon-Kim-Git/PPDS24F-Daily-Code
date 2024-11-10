def solution(A):
    N = len(A)
    A_ls = [float('-inf')] * N
    A_ls[0] = A[0]

    for i in range(1, N):
        A_ls[i] = max(A_ls[i - k] for k in range(1, 7) if i - k >= 0) + A[i]

    return A_ls[N - 1]

