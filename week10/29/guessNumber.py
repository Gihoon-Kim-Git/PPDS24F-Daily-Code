"""
<Guessing game>
: 어떤 숫자를 선택하더라도 최악의 경우에서 이기는 데 필요한 최소 비용 구하기

* DP 이용해 비용 누적

"""

# https://algo.monster/liteproblems/375

def getMoneyAmount(n):
    dp = [[0] * (n+1) for _ in range(n+1)]    # dp[l][r]: 숫자 범위 [l,r]에서 이기기 위해 필요한 최소 비용 저장

    for length in range(2, n+1):   # 범위 길이 (길이 2 이상 범위에서)
        for l in range(1, n-length+2):    # 시작 위치
            r = l + length - 1    # 끝 위치
            dp[l][r] = float('inf')
            # 중간값 k로 나누어 최악의 경우의 최소 비용 계산
            for k in range(l,r):
                cost = k + max(dp[l][k-1], dp[k+1][r])      # k를 guess하는 데 드는 비용은 k보다 작은 범위에서의 guess 값과 k보다 큰 범위에서의 guess 값 중 max + k guess 비용
                dp[l][r] = min(dp[l][r], cost)

    return dp[1][n]


print(getMoneyAmount(10))  # 16
print(getMoneyAmount(1))  # 0
print(getMoneyAmount(2))  # 1



