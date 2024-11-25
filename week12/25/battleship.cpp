#include <vector>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Check if this cell is a battleship
                if (board[i][j] == 'X') {
                    // Check if it's the start of a new battleship
                    if ((i == 0 || board[i - 1][j] != 'X') && 
                        (j == 0 || board[i][j - 1] != 'X')) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};