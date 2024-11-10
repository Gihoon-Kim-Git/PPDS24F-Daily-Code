# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(K, A):
    # Implement your solution here
    sum = 0
    count = 0
    for i in A:
        sum += i
        if sum >= K:
            count += 1
            sum = 0
    return count