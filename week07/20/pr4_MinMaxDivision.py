def is_valid_block_size(A, max_block_sum, K):
    current_sum = 0
    block_count = 1  # 최소 하나의 블록은 있어야 함
    
    for element in A:
        if current_sum + element > max_block_sum:
            block_count += 1  # 새로운 블록 시작
            current_sum = element
            if block_count > K:
                return False
        else:
            current_sum += element
            
    return True

def solution(K, M, A):
    # 이진 탐색의 범위: 가장 큰 값에서 전체 합까지
    lower_bound = max(A)  # 최소값은 배열에서 가장 큰 값
    upper_bound = sum(A)  # 최대값은 배열의 모든 값의 합
    
    result = upper_bound
    
    while lower_bound <= upper_bound:
        mid = (lower_bound + upper_bound) // 2
        if is_valid_block_size(A, mid, K):
            result = mid  # 가능한 해를 저장
            upper_bound = mid - 1  # 더 작은 블록 크기를 찾기 위해 상한 감소
        else:
            lower_bound = mid + 1  # 더 큰 블록 크기가 필요하므로 하한 증가
    
    return result
