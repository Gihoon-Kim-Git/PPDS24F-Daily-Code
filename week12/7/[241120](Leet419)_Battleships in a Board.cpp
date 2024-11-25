/*Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).
*/

/*Constraints:
    m == board.length
    n == board[i].length
    1 <= m, n <= 200
    board[i][j] is either '.' or 'X'.*/

/*수도코드
목표 : island 개수를 찾는다.    

1. dfs 함수를 짠다.(네 방향)
2. outer loop에서 dfs 함수를 새로 시작할 때마다 count++
3. return count
*/



#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    bool isValid(int i, int j, vector<vector<char>>& board){
        return (0 <= i && i < board.size()) && (0 <= j && j < board[0].size());
    }


    void dfs(int i, int j, vector<vector<char>>& board){
        //방문처리
        board[i][j] = '.';

        //이웃방문(네 방향)
        if (isValid(i-1, j, board)){
            if (board[i-1][j] == 'X'){
                dfs(i-1, j, board);
            }
        }

        if (isValid(i+1, j, board)){
            if (board[i+1][j] == 'X'){
                dfs(i+1, j, board);
            }
        }

        if (isValid(i, j-1, board)){
            if (board[i][j-1] == 'X'){
                dfs(i, j-1, board);
            }
        }

        if (isValid(i, j+1, board)){
            if (board[i][j+1] == 'X'){
                dfs(i, j+1, board);
            }
        }
    }


    int countBattleships(vector<vector<char>>& board) {
        int count = 0;

        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == 'X'){
                    count++;
                    dfs(i, j, board);
                }
            }
        }
        return count;
    }
};