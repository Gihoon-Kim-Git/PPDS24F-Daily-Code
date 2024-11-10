# 1부터 n까지의 수를 대상으로 up/down 놀이를 함
# 선택하는 수를 cost라고 했을 때 (정답 맞추면 cost=0)
# target이 어떤 수이든 target을 찾을 수 있는 cost의 최소값 구하기


"""
GPT 풀이
: Dynamic Programming
dp[i][j] -> i부터 j 구간의 수를 찾을 수 있는 maximum cost의 최소값
(i, j)에서 k를 선택하면 (i, k-1), k(정답일 때), (k+1, j) 중 한 구간에서 선택 이어나감

"""

class Solution:
    def getMoneyAmount(self, n: int) -> int:
        dp = [[0] * (n + 1) for _ in range(n + 1)]

        # 범위 길이 len을 2부터 n까지 traverse
        for len in range(2, n + 1):
            for i in range(1, n - len + 2):
                j = i + len - 1
                dp[i][j] = float('inf')
                # 최적의 k를 찾기
                for k in range(i, j):
                    cost = k + max(dp[i][k - 1], dp[k + 1][j])
                    dp[i][j] = min(dp[i][j], cost)

        return dp[1][n]