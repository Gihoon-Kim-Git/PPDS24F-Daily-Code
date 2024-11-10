
// dp[i][j]: i~j 가 남았을 때 최소로 돈 들이는 방법

// dp[i][i] = 0
// dp[i][i+1] = i
// dp[i][i+2] = i+1 = min(i + dp[i+1][i+2], i+1, i+2 + dp[i][i+1])
// dp[i][i+3] = i+2 = min(i + dp[i+1][i+3], i+1 + dp[i+2][i+3], i+2 + dp[i][i+2], , i+3 + dp[i][i+2])
// ...




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int getMoneyAmount(int n){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = 1; i < n; i++){
            dp[i][i+1] = i;
        }

        for (int i = 2; i <= n; i++) {          
            for (int j = 1; j <= n - i; j++) {  
                dp[j][j + i] = INT_MAX;

                for (int k = j; k <= j + i; k++) {
                    int left = (k - 1 >= j) ? dp[j][k - 1] : 0;
                    int right = (k + 1 <= j + i) ? dp[k + 1][j + i] : 0;
                    dp[j][j + i] = min(dp[j][j + i], k + max(left, right));
                }
            }
        }


        return dp[1][n];

    }
};