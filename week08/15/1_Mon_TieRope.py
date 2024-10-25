# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(K, A):
    # Implement your solution here
    count = 0
    length = 0
    for rope in A:
        length += rope
        if length >= K:
            count += 1
            length = 0
    return count