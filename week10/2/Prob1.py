class Solution:
    def getMoneyAmount(self, n: int) -> int:
        # dynamic programming을 사용하기 위하여 matrix 구성
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        
        # length는 2부터 시작: 1은 그냥 0이므로 dp matrix의 초기값을 그대로 활용 가능!
        for length in range(2, n + 1):
            for start in range(1, n - length + 2):
                end = start + length - 1
                dp[start][end] = float('inf')
                for pivot in range(start, end):
                    cost = pivot + max(dp[start][pivot - 1], dp[pivot + 1][end])
                    dp[start][end] = min(dp[start][end], cost)

        return dp[1][n]





sol = Solution()
print(sol.getMoneyAmount(n=10))




"""
            start = 1
            end = n
            guess = (start + end) // 2
            result = 0
            prev = 0
            while guess != findnum:
                result += guess
                if guess < findnum:
                    start = guess
                else:
                    end = guess
                prev= guess
                guess = (start + end) // 2
                if prev == guess:
                    guess += 1
            return result
        
        minval = [0] * n
        for i in range(n):
            minval[i] = findnum(n, i+1)
        print(minval)
        return sum(minval) // n
        """
