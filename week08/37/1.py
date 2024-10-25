def solution(K, A):
    current_length = 0
    r_count = 0

    for length in A:
        current_length += length
        if current_length >= K:
            r_count += 1
            current_length = 0

    return r_count
