def partition(A, K, max_sum):
    cur_sum = 0
    cnt_blocks = 1 

    for val in A:
        if cur_sum+val > max_sum:
            cur_sum = val
            cnt_blocks += 1
            if cnt_blocks > K:
                return False
        else:
            cur_sum += val
    return True

def solution(k: int, m: int, A: list) -> int:
    # should divide A -> k blocks 
    # 0 <= int size of block < n
    # large sum == maximal sum of any block 
    # goal: minimize the large sum
    low = max(A)
    high = sum(A)

    while low <= high:
        mid = (low+high)//2
        if partition(A, k, mid):
            high = mid - 1
        else:
            low = mid + 1

    return low

if __name__ == "__main__":

    A1 = [2, 1, 5, 1, 2, 2, 2]
    K = 3
    M = 5
    
    ans1 = solution(K, M, A1)

    print(ans1)