//다시풀어보기
#include <vector>
#include <limits> // std::numeric_limits 사용을 위해 필요

class Solution {
public:
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int min(int a, int b) {
        return (a < b) ? a : b;
    }

    int getMoneyAmount(int n) {
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

        for (int length = 2; length <= n; length++) {
            for (int start = 1; start <= n - length + 1; start++) {
                int end = start + length - 1;
                dp[start][end] = std::numeric_limits<int>::max(); // 무한대 초기화

                for (int k = start; k < end; k++) {
                    int cost = k + max((k - 1 >= start ? dp[start][k - 1] : 0),
                                       (k + 1 <= end ? dp[k + 1][end] : 0));
                    dp[start][end] = min(dp[start][end], cost);
                }
            }
        }

        return dp[1][n];
    }
};
