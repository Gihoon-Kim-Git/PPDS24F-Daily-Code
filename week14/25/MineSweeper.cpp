#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0], c = click[1];
        if (board[r][c] == 'M') {
            // Clicked on a mine, game over
            board[r][c] = 'X';
            return board;
        }

        reveal(board, r, c);
        return board;
    }

private:
    // Directions for the 8 neighbors (up, down, left, right, and diagonals)
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

    void reveal(vector<vector<char>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();

        // If already revealed or not an unrevealed empty square, stop
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'E') return;

        // Count how many mines are adjacent
        int mineCount = 0;
        for (auto& dir : directions) {
            int nr = r + dir[0], nc = c + dir[1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (board[nr][nc] == 'M') mineCount++;
        }

        if (mineCount > 0) {
            // Reveal this cell as a digit
            board[r][c] = '0' + mineCount;
        } else {
            // Reveal as blank 'B'
            board[r][c] = 'B';
            // Recursively reveal neighbors
            for (auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                reveal(board, nr, nc);
            }
        }
    }
};