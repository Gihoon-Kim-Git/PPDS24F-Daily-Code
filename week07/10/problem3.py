def solution(A):
    A.sort()
    max1 = A[-1] * A[-2] * A[-3] 
    max2 = A[0] * A[1] * A[-1]
    return max(max1, max2)


if __name__== "__main__":

    A1 = [-3, 1, 2, -2, 5, 6]
    ans1 = solution(A1)
    print(ans1)