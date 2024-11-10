class Solution(object):
    def getMoneyAmount(self, n):
        memo = {} # 중복은 제외하기 위한 메모이제이션

        def dp(left, right):
            if (left, right) in memo:
                return memo[(left, right)]
            if left >= right:
                return 0
            ans = float('inf')
            for pick in range(left, right + 1):
                leftCost = dp(left, pick - 1) + pick
                rightCost = dp(pick + 1, right) + pick
                cost = max(leftCost, rightCost)
                ans = min(ans, cost)
            memo[(left, right)] = ans
            return ans

        return dp(1, n)

if __name__ == "__main__":
    result = Solution()
    print(result.getMoneyAmount(56))
    # print(result.getMoneyAmount(16))
    # print(result.getMoneyAmount(10))
    # print(result.getMoneyAmount(5))
    # print(result.getMoneyAmount(2))
    # print(result.getMoneyAmount(1))