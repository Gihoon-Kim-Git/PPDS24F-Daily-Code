def solution(A):
    N = len(A)
    # sort 진행
    A.sort()
    # Case1. 음수 2개, 양수인 경우: 음수곱과 sorted list에서 큰값순 3개 곱해서 크기 비교
    if A[0] < 0 and A[1] < 0 and A[N-1] > 0:
        return max(A[0] * A[1] * A[N-1], A[N-1] * A[N-2] * A[N-3])
    # Case2. 음수가 1개이하인 경우, 맨 뒤의 3개를 곱하는 것이 제일 큼(마지막 3번째가 음수이더라도 마찬가지)
    else:
        return A[N-1] * A[N-2] * A[N-3]
    
print(solution([-3, 1, 2, -2, 5, 6]))