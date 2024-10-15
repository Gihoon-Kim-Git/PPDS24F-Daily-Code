def solution(A):
    B = sorted(A)
    if (B[-1] * B[-2] * B[-3] > B[-1] * B[0] * B[1]):
        return B[-1] * B[-2] * B[-3]
    return B[-1] * B[0] * B[1]

if __name__ == "__main__":
    A = [-7, 1, 2, -4, 5, 6]
    print(solution(A))