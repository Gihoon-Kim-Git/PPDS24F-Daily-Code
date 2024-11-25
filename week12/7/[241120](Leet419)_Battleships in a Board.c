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


#include <stdio.h>
#include <stdlib.h>

void dfs(int i, int j, char** board, int boardSize, int* boardColSize){
    if ((0 <= i && i < boardSize) && (0 <= j && j < *boardColSize) && board[i][j] == 'X'){
        board[i][j] = '.';

        dfs(i-1, j, board, boardSize, boardColSize);
        dfs(i+1, j, board, boardSize, boardColSize);
        dfs(i, j-1, board, boardSize, boardColSize);
        dfs(i, j+1, board, boardSize, boardColSize);
    }
    else 
        return;
}


int countBattleships(char** board, int boardSize, int* boardColSize) {
    int count = 0;

    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < *boardColSize; j++){
            if (board[i][j] == 'X'){
                count++;
                dfs(i, j, board, boardSize, boardColSize);
            }
        }
    }
    return count;
}