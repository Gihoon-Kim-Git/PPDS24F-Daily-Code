def solution(K, M, A):
    # K, M: int, A: list of length N, max(A) <= M
    # 배열 A를 최대 K-1번 쪼개어 쪼개진 배열의 합 중 제일 큰 값을 제일 작게 만드는 것이 목표: Min(Max) division
    N = len(A)
    minval = max(A)  # 전체를 모두 하나씩 쪼갰을 때, 그 중 제일 큰 값이 list A의 최소값이 됨
    maxval = sum(A)  # 하나도 쪼개지 않은 경우, 가질 수 있는 최대값이 됨
    result = float('inf')  # 초기값으로 inf 지정

    # base case
    if K == 1:
        return maxval
    if K == N:
        return minval
    if minval == maxval:
        return minval

    while minval <= maxval:
        mid = (minval + maxval) // 2
        if is_valid(A, K, mid):
            maxval = mid - 1
        else:
            minval = mid + 1

    return minval

def is_valid(A, K, max_sum):
    block_sum = 0
    block_count = 0

    for element in A:
        block_sum += element
        if block_sum > max_sum:
            block_sum = element
            block_count += 1

    return block_count + 1 <= K



print(solution(3, 5, [2, 1, 5, 1, 2, 2, 2]))