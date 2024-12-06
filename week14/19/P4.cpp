#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateEmpty(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] != 'E') return board;
        int n_row = board.size();
        int n_col = board[0].size();
        vector<vector<int>> directions = {{-1,-1},{-1,0},{-1,1},{0,-1},
                                          {0,1},{1,-1},{1,0},{1,1}};
        for (auto d: directions) {
            if (0 <= x+d[0] && x+d[0] < n_row &&
                0 <= y+d[1] && y+d[1] < n_col &&
                board[x+d[0]][y+d[1]] == 'M') {
                board[x][y] += 1;
            }
        }
        if (board[x][y] == 'E') board[x][y] = 'B';
        else {
            board[x][y] = '0' + (board[x][y] - 'E');
            return board;
        }
        for (auto d: directions) {
            if (0 <= x+d[0] && x+d[0] < n_row &&
                0 <= y+d[1] && y+d[1] < n_col &&
                board[x+d[0]][y+d[1]] == 'E') {
                board = updateEmpty(board, x+d[0], y+d[1]);
            }
        }
        return board;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];
        if (board[x][y] == 'M') board[x][y] = 'X';
        else board = updateEmpty(board, x, y);
        return board;
    }
};

int main() {
    vector<vector<char>> board = {{'E','E','E','E','E'},
                                  {'E','E','M','E','E'},
                                  {'E','E','E','E','E'},
                                  {'E','E','E','E','E'}};
    vector<int> click = {3,0};
    Solution result;
    vector<vector<char>> answer = result.updateBoard(board, click);
    for (auto i: answer) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}