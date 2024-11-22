// Input: board = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}}
// Output: 2

// Input: board = {{'.'}}
// Output: 0

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
    public:
        bool alldots(vector<vector<char>>& board) {
            bool result = true;
            int rowN = board.size();
            int colN = board[0].size();

            for (int i = 0; i < rowN; i++) {
                for (int j = 0; j < colN; j++) {
                    if (board[i][j] =='X') {
                        result = false;
                    }
                }
            }     
            return result;     
        }
        // bool isdot(vector<vector<char>>& board, int x, int y) {
        //     int rowN = board.size();
        //     int colN = board[0].size();

        //     if ((x<0)||(x>=rowN) || (y<0)||(y>=colN)) {
        //         return false;
        //     } else {
        //         if (board[x][y]=='.') {
        //             return true;
        //         }
        //     }
        //     return false;
        // }
        void dfs(vector<vector<char>>& board, int x, int y) {
            int rowN = board.size();
            int colN = board[0].size();

            //(1). edge case: 존재하지 않는 cell
            if ((x<0)||(x>=rowN) || (y<0)||(y>=colN)) {
                return;
            }

            //(2). 존재하면 땅인지 배인지 확인. 땅이면 return
            if (board[x][y] == '.') {
                return;
            }            //(3). 배라면 더 탐색. 
            else if (board[x][y] == 'X') {
            board[x][y] = '.';

            dfs(board, x+1, y);
            dfs(board, x-1, y);
            dfs(board, x, y+1);
            dfs(board, x, y-1);
            }
        }
        int countBattleships(vector<vector<char>>& board) {
            int rowN = board.size();
            int colN = board[0].size();

            int numBs = 0;
            int x = 0; int y = 0;
            while (alldots(board)== false) {
                for (int i = 0; i < rowN; i++) {
                    for (int j = 0; j < colN; j++) {
                        if (board[i][j]== 'X') {
                            dfs(board, i, j);
                            numBs++;
                        }
                    }
                    }
            }

            return numBs;
        }
};

int main() {

    Solution mysol;

    vector<vector<char>> board1 = {
        {'X','.','.','X'},
        {'X','.','.','X'},
        {'X','.','.','X'}
    };    
    vector<vector<char>> board2 = {{'.'}};
    vector<vector<char>> board3 = {
        {'X','.','.','X'},
        {'.','X','.','X'},
        {'.','X','.','X'}
    };
    vector<vector<char>> board4 = {
        {'X','X','.','X'},
        {'.','.','.','X'},
        {'.','.','.','X'}
    };
    
    cout << mysol.countBattleships(board1) << endl;
    cout << mysol.countBattleships(board2) << endl;
    cout << mysol.countBattleships(board3) << endl;
    cout << mysol.countBattleships(board4) << endl;



}