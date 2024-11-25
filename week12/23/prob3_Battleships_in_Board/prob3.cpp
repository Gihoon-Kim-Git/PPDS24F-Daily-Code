#include <iostream>
#include <vector>
using namespace std;

int countBattleships(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Count only the top-left corner of each battleship
            if (board[i][j] == 'X') {
                if (i > 0 && board[i-1][j] == 'X') continue; // Check above
                if (j > 0 && board[i][j-1] == 'X') continue; // Check left
                count++;
            }
        }
    }
    return count;
}

// Example usage
int main() {
    vector<vector<char>> board = {
        {'X', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'}
    };
    cout << countBattleships(board) << endl; // Output: 2
    return 0;
}
