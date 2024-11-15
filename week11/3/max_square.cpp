#include <vector>
#include <algorithm>

using namespace std;

/*
 * Class: Solution
 * ----------------
 * Provides a method to find the largest square containing only 1's in a binary matrix.
 */
class Solution {
public:
    /*
     * Function: maximalSquare
     * -----------------------
     * Finds the largest square containing only 1's in a binary matrix and returns its area.
     *
     * Examples:
     * ---------
     * Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
     * Output: 4
     *
     * Input: matrix = [["0","1"],["1","0"]]
     * Output: 1
     *
     * Approach:
     * ---------
     * 1. Use dynamic programming to calculate the size of the largest square ending at each cell.
     * 2. Define `dp[i][j]` as the size of the largest square whose bottom-right corner is at `(i, j)`.
     *    - If matrix[i][j] == '1', then:
     *      dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
     * 3. Keep track of the maximum size of any square and return its area (size * size).
     */
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0; // No rows or columns
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        int max_side = 0;

        // Create a DP table
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        // Fill the DP table
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // Base case for the first row or column
                    } else {
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    max_side = max(max_side, dp[i][j]); // Track the largest side length
                }
            }
        }

        return max_side * max_side; // Return the area of the largest square
    }
};