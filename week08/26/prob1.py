# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(K, A):
    # Implement your solution here
    cnt = 1
    # store sum of ropes
    ropes = 0
    for x in A:
        ropes += x
        if ropes >= K:
            cnt += 1
            ropes = 0
    if ropes < K:
        cnt -= 1
    return cnt

