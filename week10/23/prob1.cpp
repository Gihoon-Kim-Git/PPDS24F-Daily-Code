// 375. Guess Number Higher or Lower II
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        function<int(int, int)> calculateCost = [&](int start, int end) {
            if (start >= end) return 0;
            if (dp[start][end] != 0) return dp[start][end];

            int minCost = INT_MAX;
            for (int guess = (start + end) / 2; guess <= end; ++guess) {
                int cost = guess + max(calculateCost(start, guess - 1), calculateCost(guess + 1, end));
                minCost = min(minCost, cost);
            }

            dp[start][end] = minCost;
            return minCost;
        };

        return calculateCost(1, n);
    }
};