#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool find(vector<vector<char>>& board, string& word, int row, int col) {
        int n_row = board.size();
        int n_col = board[0].size();
        vector<vector<bool>> visited(n_row, vector<bool>(n_col, false));
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        function<bool(int, int, int)> find_util = [&](int v, int w, int i) {
            if (i == word.size() - 1) {
                return true;
            }
            visited[v][w] = true;
            for (auto d : directions) {
                int nv = v + d.first;
                int nw = w + d.second;
                if (nv >= 0 && nv < n_row && nw >= 0 && nw < n_col && 
                    !visited[nv][nw] && board[nv][nw] == word[i + 1]) {
                    if (find_util(nv, nw, i + 1)) {
                        return true;
                    }
                }
            }
            visited[v][w] = false;
            return false;
        };

        return find_util(row, col, 0);
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n_row = board.size();
        int n_col = board[0].size();
        for (int i = 0; i < n_row; ++i) {
            for (int j = 0; j < n_col; ++j) {
                if (board[i][j] == word[0] && find(board, word, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};


int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    Solution result;
    cout << result.exist(board, "ABCCED") << endl;

    return 0;
}