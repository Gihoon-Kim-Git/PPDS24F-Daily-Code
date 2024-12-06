#include <vector>

using namespace std;


class Solution {
private:
    vector<vector<int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<bool>> visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

        // cout << "Ready to click!" << endl;

        if (board[click[0]][click[1]] == 'M') {
            clickM(board, click);
        }
        else if (board[click[0]][click[1]] == 'E') {
            clickE(board, click, visited);
        }

        return board;
    }

    void clickM(vector<vector<char>>& board, vector<int>& click) {
        board[click[0]][click[1]] = 'X';
        return;
    }

    int countAdjMines(vector<vector<char>>& board, vector<int>& click) {
        int cnt = 0;
        for (auto& d : directions) {
            int i = click[0] + d[0];
            int j = click[1] + d[1];
            if (i < 0 || i >= board.size()) continue;
            if (j < 0 || j >= board[0].size()) continue;
            if (board[i][j] == 'M') {
                cnt += 1;
            }
        }
        return cnt;
    }

    void clickE(vector<vector<char>>& board, vector<int>& click, vector<vector<bool>>& visited) {
        // base case 1 : out of range
        if (click[0] < 0 || click[0] >= board.size()) return;
        if (click[1] < 0 || click[1] >= board[0].size()) return;

        // cout << "\nindex range is okay : (" << click[0] << ", " << click[1] << ")" << endl;

        // base case 2 : visited
        if (visited[click[0]][click[1]]) return;
        visited[click[0]][click[1]] = true;

        // cout << "Not visited yet, so click : (" << click[0] << ", " << click[1] << ")" << endl;

        int cnt = countAdjMines(board, click);

        // cout << "adj mines : " << cnt << endl;

        // base case 3 : There exist adjacent mines
        if (cnt > 0) {
            board[click[0]][click[1]] = cnt + '0';
            return;
        }

        // recursive case : No adjacent mines
        else {
            // cout << "no adj mines" << endl;

            board[click[0]][click[1]] = 'B';
            for (auto& d : directions) {
                vector<int> clickNext = {click[0] + d[0], click[1] + d[1]};
                // cout << "clickNext : (" << clickNext[0] << ", " << clickNext[1] << ")" << endl;
                if (clickNext[0] < 0 || clickNext[0] >= board.size()) continue;
                if (clickNext[1] < 0 || clickNext[1] >= board[0].size()) continue;
                if (board[clickNext[0]][clickNext[1]] == 'E') {
                    clickE(board, clickNext, visited);
                }
            }
            return;
        }
    }
};
