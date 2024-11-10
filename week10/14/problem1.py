# week 10

# Monday. [Guess Number Higher or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/)

class Solution:
    def getMoneyAmount(self, n: int) -> int:
        # dp[i][j] := min money you need to guarantee a win of picking i..j
        dp = [[0] * (n + 2) for _ in range(n + 2)]

        # iterate over all possible subranges of [1, n]
        for d in range(1, n + 1):
            for i in range(1, n - d + 1):
                j = i + d
                # initialize dp[i][j] to infinity
                dp[i][j] = math.inf
                # iterate over all possible guesses k between i and j
                for k in range(i, j + 1):
                    # compute the maximum cost of guessing k and the worst-case scenario for each of the two subranges
                    cost = max(dp[i][k-1], dp[k+1][j]) + k
                    # take the minimum cost over all possible guesses k
                    dp[i][j] = min(dp[i][j], cost)

        # the minimum cost of guessing a number between 1 and n is stored in dp[1][n]
        return dp[1][n]