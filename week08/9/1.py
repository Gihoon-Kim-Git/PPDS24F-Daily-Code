def solution(K, A):
    count = 0
    current_length = 0

    for a in A:
        current_length += a
        if current_length >= K:
            count += 1
            current_length = 0 