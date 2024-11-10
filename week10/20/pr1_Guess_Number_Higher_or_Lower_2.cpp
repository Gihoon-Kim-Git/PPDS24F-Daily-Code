#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
class Solution {
public:
    int getMoneyAmount(int n) {
        // vector<int> dp(n+1,0);
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int length = 2; length<=n; length++){
            for(int i=1;i<=n-length+1;i++){
                int j = i + length - 1;
                dp[i][j] = INT_MAX;
                
                for(int k=i;k<j;k++){
                    int cost = k + max(dp[i][k-1],dp[k+1][j]);
                    dp[i][j] = min(cost,dp[i][j]);
                }
            }
        }
        return dp[1][n];
    }
};