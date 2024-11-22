#include <cassert>
#include <cstdbool>
#include <vector>

using namespace std;

const vector<pair<int, int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isValidLoc(int r, int c, int m, int n) {
  return r >= 0 && r < m && c >= 0 && c < n;
}

void dfs(const vector<vector<char>>& board, int r, int c, int m, int n,
         vector<vector<bool>>& visited) {
  visited[r][c] = true;

  for (auto dir : dirs) {
    int nr = r + dir.first;
    int nc = c + dir.second;
    if (isValidLoc(nr, nc, m, n) && board[nr][nc] == 'X' && !visited[nr][nc]) {
      dfs(board, nr, nc, m, n, visited);
    }
  }
}

int countBattleships(vector<vector<char>>& board) {
  int m = board.size();
  int n = board[0].size();
  vector<vector<bool>> visited(m, vector<bool>(n, false));

  int cnt = 0;

  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (visited[r][c] == true) continue;
      if (board[r][c] == '.') {
        visited[r][c] = true;
        continue;
      }
      dfs(board, r, c, m, n, visited);
      ++cnt;
    }
  }
  return cnt;
}

int main() {
  vector<vector<char>> board1 = {
      {'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
  assert(countBattleships(board1) == 2);
  vector<vector<char>> board0 = {{'.'}};
  assert(countBattleships(board0) == 0);
}