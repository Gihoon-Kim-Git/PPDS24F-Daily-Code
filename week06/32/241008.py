# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # Implement your solution here
    arr = [float('-inf')] * len(A)
    arr[0] = A[0]

    for i in range(1, len(A)):
        for j in range(1, 7):
            if i-j >=0:
                arr[i] = max(arr[i], arr[i-j]+A[i])

    return arr[len(A)-1]
