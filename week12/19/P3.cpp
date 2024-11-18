#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> dfs_util(int v, int w, int n_row, int n_col,
                                 vector<vector<char>>& board,
                                 vector<vector<int>>& visited) {
        visited[v][w] = 1;
        if (0 <= v-1 && not visited[v-1][w] && board[v-1][w] == 'X')
            visited = dfs_util(v-1, w, n_row, n_col, board, visited);
        if (v+1 < n_row && not visited[v+1][w] && board[v+1][w] == 'X')
            visited = dfs_util(v+1, w, n_row, n_col, board, visited);
        if (0 <= w-1 && not visited[v][w-1] && board[v][w-1] == 'X')
            visited = dfs_util(v, w-1, n_row, n_col, board, visited);
        if (w+1 < n_col && not visited[v][w+1] && board[v][w+1] == 'X')
            visited = dfs_util(v, w+1, n_row, n_col, board, visited);
        return visited;
    }

    int countBattleships(vector<vector<char>>& board) {
        int n_row = board.size();
        int n_col = board[0].size();
        vector<vector<int>> visited = {};
        for (int i=0; i<n_row; i++) {
            vector<int> temp(n_col, 0);
            visited.push_back(temp);
        }

        int cnt = 0;
        for (int i=0; i<n_row; i++) {
            for (int j=0; j<n_col; j++) {
                if (visited[i][j] == 0 && board[i][j] == 'X') {
                    visited = dfs_util(i, j, n_row, n_col, board, visited);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};


int main() {
    vector<vector<char>> board = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
    Solution result;
    cout << result.countBattleships(board) << endl;

    return 0;
}