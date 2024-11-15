#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxSquareLen = 0;

        // DP 배열을 정의하고 초기화합니다.
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));

        // DP를 통해 각 위치에서의 최대 정사각형 한 변의 길이를 계산합니다.
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    maxSquareLen = max(maxSquareLen, dp[i][j]);
                }
            }
        }

        // 최대 변의 길이를 제곱하여 최대 정사각형의 넓이를 반환합니다.
        return maxSquareLen * maxSquareLen;
    }
};