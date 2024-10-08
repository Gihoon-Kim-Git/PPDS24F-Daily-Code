def solution1(A):
    result = 0
    if A[-1] > 0:
        return numberSolitaire(A, result)
    else:
        return numberSolitaire(A, result) + A[-1]

def numberSolitaire(A, result):
    result += A[0]
    r1 = 0
    r2 = 0
    r3 = 0
    r4 = 0
    r5 = 0
    r6 = 0
    if len(A) > 1:
        r1 = numberSolitaire(A[1:], result) # add 1
    if len(A) > 2:
        r2 = numberSolitaire(A[2:], result) # add 2
    if len(A) > 3:
        r3 = numberSolitaire(A[3:], result) # add 3
    if len(A) > 4:
        r4 = numberSolitaire(A[4:], result) # add 4
    if len(A) > 5:
        r5 = numberSolitaire(A[5:], result) # add 5
    if len(A) > 6:
        r6 = numberSolitaire(A[6:], result) # add 6
    return max(result, r1, r2, r3, r4, r5, r6)


def solution2(A):
    if len(A) == 1:
        return A[0]
    result = float('-inf')
    for i in range(1,7):
        if len(A) > i:
            temp = solution2(A[:-i])
            result = max(result, temp)
    return result + A[-1]

def solution3(A):
    N = len(A)
    
    # dp 배열 생성, dp[i]는 A[i]에 도착했을 때의 최대 점수를 저장
    dp = [-float('inf')] * N
    dp[0] = A[0]  # 첫 번째 위치의 값은 그 자체가 최대 점수

    # 배열을 차례로 순회하며 dp 값을 채워나감
    for i in range(1, N):
        # i 번째 칸까지 도달할 수 있는 방법은 최대 6칸 전에서 오는 것
        for dice in range(1, 7):
            if i - dice >= 0:  # 배열 범위를 넘지 않도록 확인
                dp[i] = max(dp[i], dp[i - dice] + A[i])

    # 마지막 칸에서의 최대 점수 반환
    return dp[-1]

if __name__ == "__main__":
    A = [2, -3, 1, 9, 3, -1, 2, -4]
    print(solution1(A))
    print(solution2(A))
    print(solution3(A))