/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square
containing only 1's and return its area.

Example 1:

Input: matrix =
[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:

Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:

Input: matrix = [["0"]]
Output: 0


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

int GetPrevMaxLen(int r, int c, int m, int n, const vector<vector<int>>& M) {
  if (r >= 0 && r < m && c >= 0 && c < n) return M[r][c];
  return 0;
}

int maximalSquare(vector<vector<char>>& matrix) {
  int m = matrix.size();
  int n = matrix[0].size();

  // Bottom-Right Corner as index
  // Side length as value
  vector<vector<int>> M(m, vector<int>(n, 0));

  int max_len = 0;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (matrix[r][c] == '0') continue;
      // Up, Left-Up, Left: because of how we traverse the matrix
      M[r][c] = min(min(GetPrevMaxLen(r - 1, c, m, n, M),
                        GetPrevMaxLen(r - 1, c - 1, m, n, M)),
                    GetPrevMaxLen(r, c - 1, m, n, M)) +
                1;
      max_len = max(max_len, M[r][c]);
    }
  }

  return max_len * max_len;
}

int main() {
  vector<vector<char>> matrix1 = {{'1', '0', '1', '0', '0'},
                                  {'1', '0', '1', '1', '1'},
                                  {'1', '1', '1', '1', '1'},
                                  {'1', '0', '0', '1', '0'}};
  assert(maximalSquare(matrix1) == 4);

  vector<vector<char>> matrix2 = {{'0', '1'}, {'1', '0'}};
  assert(maximalSquare(matrix2) == 1);

  vector<vector<char>> matrix3 = {{'0'}};
  assert(maximalSquare(matrix3) == 0);
}