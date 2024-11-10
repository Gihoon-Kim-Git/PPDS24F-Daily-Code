/*
Write an efficient algorithm that searches for a value target in an m x n
integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Examples:

Input: matrix =
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
target = 5 Output: true

Input: matrix =
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
target = 20 Output: false
*/
#include <cassert>
#include <cmath>
#include <cstdbool>
#include <vector>

using namespace std;

bool RecursiveHelper(vector<vector<int>>& matrix, int target, int rs, int re,
                     int cs, int ce) {
  if (rs > re || cs > ce) return false;

  // Smaller than the smallest
  if (target < matrix[rs][cs]) return false;
  // Greater than the largest
  if (target > matrix[re][ce]) return false;

  int cm = cs + floor((ce - cs) / 2);
  int r = rs;
  while (r <= re && matrix[r][cm] <= target) {
    if (matrix[r][cm] == target) return true;
    ++r;
  }

  return RecursiveHelper(matrix, target, r, re, cs, cm - 1) ||
         RecursiveHelper(matrix, target, rs, r - 1, cm + 1, ce);
}

bool SearchMatrix(vector<vector<int>>& matrix, int target) {
  int m = matrix.size(), n = matrix[0].size();
  return RecursiveHelper(matrix, target, 0, m - 1, 0, n - 1);
}

int main() {
  vector<vector<int>> matrix1 = {{1, 4, 7, 11, 15},
                                 {2, 5, 8, 12, 19},
                                 {3, 6, 9, 16, 22},
                                 {10, 13, 14, 17, 24},
                                 {18, 21, 23, 26, 30}};
  assert(SearchMatrix(matrix1, 5) == true);
  assert(SearchMatrix(matrix1, 20) == false);
  assert(SearchMatrix(matrix1, 19) == true);

  vector<vector<int>> matrix2 = {{-5}};
  assert(SearchMatrix(matrix2, -10) == false);

  vector<vector<int>> matrix3 = {{-1, -1}};
  assert(SearchMatrix(matrix3, 0) == false);
}