#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        for (int length = 2; length < n+1; length++) {
            for (int start = 1; start < n - length + 2; start++) {
                int end = start + length - 1;
                dp[start][end] = INT_MAX;
                for (int x = start; x < end; x++) {
                    int cost = x + max(dp[start][x-1], dp[x+1][end]);
                    dp[start][end] = min(cost ,dp[start][end]);
                }
            }
        }
        return dp[1][n];
    }
};