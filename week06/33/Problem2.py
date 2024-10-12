# index가 0 ~ N-1인 Array a 가 주어졌을 때,
# 주사위 던지기를 해서 N-1번째 자리까지 가려고 함.
# 이 때, 각 자리의 점수(a[i]=k일 때 k가 점수가 됨)를 합산하여 얻을 수 있는 최대 점수 구하기
# 단, 이동해야하는 자리가 N-1을 벗어나는 경우 이동하지 않으며 이는 점수에도 합산되지 않음

"""
GPT 사용 O
recursion이 아니라 dynamic programming으로 풀기!
"""

def Solution(A: list) -> int:
    N = len(A)
    score = [-99999] * N
    score[0] = A[0]
    
    for i in range(1, N):
        # score array에서 i-6 ~ i번째 array에서 가장 큰 값 찾아서 A[i] 더하기
        # max(0, i-6): i가 6보다 작을 때 음수 index 갖는 것 방지
        score = max(score[max(0, i-6):i]) + A[i]
    
    return score[N-1]