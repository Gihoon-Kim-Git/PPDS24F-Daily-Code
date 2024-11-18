
#include <vector>
using namespace std;

// """ SQUARE """

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        // dp
        // dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1 (1일 경우)
        // 0 -> 0

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int max_len = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    max_len = max(max_len, dp[i][j]);
                }
            }
        }

        return max_len * max_len;   


        
    }
};