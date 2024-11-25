/*
Leetcode 419. Battleships in a Board
Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).



Example 1:


Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
Output: 2
Example 2:

Input: board = [["."]]
Output: 0
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    pair<int, int> p[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    void flooding(vector<vector<char>> &board, int i, int j)
    {
        board[i][j] = '.';
        for (int k = 0; k < 4; k++)
        {
            int in = i + p[k].first;
            int jn = j + p[k].second;
            if (in >= 0 && jn >= 0 && in < board.size() && jn < board[0].size() && board[in][jn] == 'X')
            {
                flooding(board, in, jn);
            }
        }
    }
    int countBattleships(vector<vector<char>> &board)
    {
        int count = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'X')
                {
                    count += 1;
                    flooding(board, i, j);
                }
            }
        }
        return count;
    }
};