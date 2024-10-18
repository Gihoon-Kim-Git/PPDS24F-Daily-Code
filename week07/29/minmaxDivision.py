# Divide array A into K blocks and minimize the largest sum of any block.
def valid_devision(A, max_block_sum, K):
    current_sum = 0
    blocks = 1  # 최소

    for num in A:
        if current_sum + num > max_block_sum:     # [2,1,5,1], [2,2,2]
            blocks += 1      # 새로운 블록 시작
            current_sum = num     # 현재 블록을 num으로 시작
            if blocks > K:
                return False
        else:
            current_sum += num
    
    return True     # 아직 K 안 넘음 = 더 쪼갤 수 있음




def solution(K,M,A):
    low = max(A)
    high = sum(A)

    if K == 1:
        return high
    elif K >= len(A):   # [],[1],[2],...
        return low
    else:
        while low <= high:
            mid = (low+high) // 2      # max block sum
            if valid_devision(A, mid, K):      
                high = mid - 1   # 더 작은 값 가능한지 확인
            else:
                low = mid + 1   # 블록 나눌 수 없음
        
        return low   # 최소한의 최대 블록 합
    

print(solution(3,5,[2,1,5,1,2,2,2]))