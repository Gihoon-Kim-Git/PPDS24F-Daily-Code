#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
       vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int len = 2; len <= n; ++len) {  
            for (int start = 1; start <= n - len + 1; ++start) {
                int end = start + len - 1;
                dp[start][end] = INT_MAX;
                for (int k = start; k < end; ++k) {
                    int cost = k + max(dp[start][k - 1], dp[k + 1][end]);
                    dp[start][end] = min(dp[start][end], cost);
                }
            }
        }

        return dp[1][n];
    }
};