#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> updateBoard(vector<vector<string>>& board, vector<int>& click) {
        int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dy[8] = {1, -1, 0, 1, -1, 1, 0, -1};
        int x = click[0], y = click[1];

        if (board[x][y] == "M") {
            board[x][y] = "X";
            return board;
        }

        int count = 0;
        if (board[x][y] == "E") {
            // Count the number of mines around the clicked position
            for (int i = 0; i < 8; ++i) {
                int cx = x + dx[i];
                int cy = y + dy[i];
                if (valid(board, cx, cy) && board[cx][cy] == "M") {
                    count++;
                }
            }

            if (count == 0) {
                board[x][y] = "B";  // No mines around, set as 'B'
                for (int j = 0; j < 8; ++j) {
                    int cx = x + dx[j];
                    int cy = y + dy[j];
                    vector<int> temp = {cx,cy};
                    if (valid(board, cx, cy)) {
                        updateBoard(board, temp);
                    }
                }
            } else {
                board[x][y] = to_string(count);  // Set the count as string
            }
        }
        return board;
    }

private:
    bool valid(const vector<vector<string>>& board, int x, int y) {
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
    }
};

int main() {
    Solution solution;
    vector<vector<string>> board = {
        {"E", "E", "E", "E", "E"},
        {"E", "E", "M", "E", "E"},
        {"E", "E", "E", "E", "E"},
        {"E", "E", "E", "E", "E"}
    };
    vector<int> click = {3, 0};
    
    vector<vector<string>> updatedBoard = solution.updateBoard(board, click);

    // Print the updated board
    for (const auto& row : updatedBoard) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
