#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int row = click[0], col = click[1];

        if (board[row][col] == 'M') {
            board[row][col] = 'X';
            return board;
        }

        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
            {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };

        function<void(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'E') return;

            int mineCount = 0;
            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'M') {
                    mineCount++;
                }
            }

            if (mineCount > 0) {
                board[r][c] = '0' + mineCount;
            } else {
                board[r][c] = 'B';
                for (auto [dr, dc] : directions) {
                    dfs(r + dr, c + dc);
                }
            }
        };

        dfs(row, col);
        return board;
    }
};