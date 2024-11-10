# This function calculates the minimum amount of money required to guarantee a win
# in the Guessing Game, using dynamic programming to optimize performance.
# The goal is to minimize the maximum loss in the worst-case scenario when guessing.
# We use a bottom-up approach to build the solution for smaller ranges first,
# then extend the solution to cover the entire range from 1 to n.

def getMoneyAmount(n: int) -> int:
    # initialization: DP table (2D list dp of size (n+1) x (n+1) initialized with zeros)
    # dp[i][j] stores the minimum cost to guarantee a win in the range [i, j]
    dp = [[0] * (n + 1) for _ in range(n + 1)]

    # iteration over the length of range, starting from 2 (single number: zero cost)
    # solve smaller subproblems first and use those solutions to solve larger problems
    for length in range(2, n + 1):
        # iteration over the start of range
        for start in range(1, n - length + 2):
            end = start + length - 1
            # initialization: cost for this range
            dp[start][end] = float('inf')

            """
            Loop Over Possible Guesses: We consider each number k in the range [start, end] as a possible guess
            The cost of guessing k is the cost of k itself plus the maximum of:
            - The cost to guarantee a win in the left subrange [start, k-1]
            - The cost to guarantee a win in the right subrange [k+1, end]
            """
            # iteration over all possible numbers to guess in the range [start, end]
            for k in range(start, end):
                # if guess is k, cost = k + the worst-case cost of guessing in the two subranges
                # : [start, k - 1] and [k + 1, end]
                cost = k + max(dp[start][k - 1], dp[k + 1][end])

                # update minimum cost for the range [start, end]
                dp[start][end] = min(dp[start][end], cost)

    # answer for the entire range [1, n] is stored in dp[1][n]
    return dp[1][n]

# Example usage:
print(getMoneyAmount(10))  # Output: 16
print(getMoneyAmount(1))   # Output: 0
print(getMoneyAmount(2))   # Output: 1


"""
Problem Explanation

We are playing a Guessing Game where:
1. You need to guess a number between 1 and n.
2. Every time you guess a number x and it’s wrong, you pay x dollars.
3. If your guess is wrong, I will tell you if my number is higher or lower.
4. The objective is to minimize the maximum amount of money you might have to pay in the worst-case scenario.

Our goal is to find a strategy that guarantees we win the game while minimizing the maximum amount of money we may need to spend.

Intuition Behind the Solution

1. Worst-case Scenario: We are interested in minimizing our worst-case cost.
For each guess we make, we have to consider the worst-case cost of all possible outcomes (whether the number is higher or lower).
2. Recursive Approach:
Initially, one might think to solve this problem using a recursive approach where we try all possible guesses and calculate the cost recursively for each possibility.
However, this quickly becomes inefficient as n grows because the number of recursive calls explodes.
3. Dynamic Programming (DP) Approach:
To handle the inefficiency, we use dynamic programming. The idea is to break down the problem into smaller subproblems, solve them once, and store the results to use later.

Approach to Solve Using DP

1. Define the DP Table:
We use a 2D table dp where dp[i][j] represents the minimum amount of money needed to guarantee a win for the range [i, j].
Our goal is to compute dp[1][n], which gives the answer for the full range from 1 to n.

2. Base Cases:
If the range has only one number (like [i, i]), you don’t need to pay anything, because you already know the number. Hence, dp[i][i] = 0.
We also know that if i > j (an invalid range), dp[i][j] = 0.

3. Building the Solution Bottom-Up:
We iterate over all possible lengths of ranges, starting from 2 (since a single number has no cost).
For each length, we consider all possible starting points i and calculate the ending point j as i + length - 1.
For each range [i, j], we try all possible guesses k between i and j:
- If we choose k, our cost is k plus the maximum cost of guessing in the two subranges:
  - The left subrange: [i, k - 1]
  - The right subrange: [k + 1, j]
- We use max() because we are interested in the worst-case scenario (the maximum cost of the two subranges).

4. Minimize the Cost:
We take the minimum of all possible costs across different guesses k to ensure our strategy is optimal.

Step-by-Step Walkthrough
Let’s walk through a simple example with n = 3:

1. We need to guess a number between 1 and 3. Our DP table dp is initially filled with zeros.

2. We consider ranges of length 2 (like [1, 2] and [2, 3]):
For range [1, 2], if we guess 1:
- If it’s wrong, we pay 1 dollar, and the only remaining number is 2, so the cost is 1.
- Thus, dp[1][2] = 1.
For range [2, 3], if we guess 2:
- If it’s wrong, we pay 2 dollars, and the only remaining number is 3, so the cost is 2.
- Thus, dp[2][3] = 2.

3. Now, consider the full range [1, 3] (length 3):
If we guess 1, we pay 1 dollar. The worst-case scenario is the range [2, 3], costing 2. Total cost: 1 + 2 = 3.
If we guess 2, we pay 2 dollars. The worst-case scenario is the higher of [1, 1] and [3, 3], both costing 0. Total cost: 2 + 0 = 2.
If we guess 3, we pay 3 dollars. The worst-case scenario is the range [1, 2], costing 1. Total cost: 3 + 1 = 4.
We take the minimum of these costs: min(3, 2, 4) = 2. Hence, dp[1][3] = 2.
"""