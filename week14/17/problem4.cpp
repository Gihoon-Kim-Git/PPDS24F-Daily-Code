// You are given an m x n char matrix board representing the game board where:

// 'M' represents an unrevealed mine,
// 'E' represents an unrevealed empty square,
// 'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
// digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
// 'X' represents a revealed mine.
// You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').

// Return the board after revealing this position according to the following rules:

// If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
// If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
// If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
// Return the board when no more squares will be revealed.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

        int row = click[0];
        int col = click[1];

        if (board[row][col] == 'M'){
            board[row][col] = 'X';
            return board;
        }

        reveal(board, row, col);

        return board;
        
    }

    void reveal(vector<vector<char>>& board, int row, int col){

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'E'){
            return;
        }

        int count = 0;

        for (int i = -1; i <= 1; i++){
            for (int j = -1; j <= 1; j++){
                if (i == 0 && j == 0){
                    continue;
                }

                int newRow = row + i;
                int newCol = col + j;

                if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size() && board[newRow][newCol] == 'M'){
                    count++;
                }
            }
        }

        if (count > 0){
            board[row][col] = count + '0';
        } else {
            board[row][col] = 'B';

            for (int i = -1; i <= 1; i++){
                for (int j = -1; j <= 1; j++){
                    if (i == 0 && j == 0){
                        continue;
                    }

                    reveal(board, row + i, col + j);
                }
            }
        }
    }
};