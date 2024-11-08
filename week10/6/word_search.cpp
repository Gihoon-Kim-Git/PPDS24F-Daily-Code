/*
Given an m x n grid of characters board and a string word, return true if word
exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where
adjacent cells are horizontally or vertically neighboring. The same letter cell
may not be used more than once.
*/
#include <cassert>
#include <cstdbool>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

using Coord = tuple<int, int>;
const vector<Coord> DIRS = {Coord(-1, 0), Coord(0, 1), Coord(1, 0),
                            Coord(0, -1)};

bool helper(int r, int c, int i, int m, int n, vector<vector<char>>& board,
            string word, vector<vector<bool>>& visited) {
  if (i == word.size() - 1 && board[r][c] == word[i]) return true;
  if (board[r][c] != word[i]) return false;
  bool final_res = false;
  for (auto drdc : DIRS) {
    int dr = get<0>(drdc), dc = get<1>(drdc);
    int nr = r + dr, nc = c + dc;
    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
      visited[nr][nc] = true;
      final_res =
          final_res || helper(nr, nc, i + 1, m, n, board, word, visited);
      visited[nr][nc] = false;
    }
  }
  return final_res;
}

bool exist(vector<vector<char>>& board, string word) {
  int m = board.size();
  int n = board[0].size();
  bool final_res = false;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      if (board[r][c] == word[0]) {
        visited[r][c] = true;
        final_res = final_res || helper(r, c, 0, m, n, board, word, visited);
      }
    }
  }
  return final_res;
}

int main() {
  vector<vector<char>> b1 = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  assert(exist(b1, "ABCCED"));
  assert(exist(b1, "SEE"));
  assert(!exist(b1, "ABCB"));
  vector<vector<char>> b2 = {{'a', 'b'}, {'c', 'd'}};
  assert(exist(b2, "acdb"));
}