def solution(K, A):
    count = 0
    current_length = 0
    
    for length in A:
        current_length += length
        if current_length >= K:
            count += 1
            current_length = 0  
            
    return count