#include <stdio.h>
#include <stdlib.h>

void dfs_util(int v, int w, int n_row, int n_col, char** board, int** visited) {
    visited[v][w] = 1;
    if (0 <= v-1 && visited[v-1][w] == 0 && board[v-1][w] == 'X')
        dfs_util(v-1, w, n_row, n_col, board, visited);
    if (v+1 < n_row && visited[v+1][w] == 0 && board[v+1][w] == 'X')
        dfs_util(v+1, w, n_row, n_col, board, visited);
    if (0 <= w-1 && visited[v][w-1] == 0 && board[v][w-1] == 'X')
        dfs_util(v, w-1, n_row, n_col, board, visited);
    if (w+1 < n_col && visited[v][w+1] == 0 && board[v][w+1] == 'X')
        dfs_util(v, w+1, n_row, n_col, board, visited);
}

int countBattleships(char** board, int boardSize, int* boardColSize) {
    int** visited = (int**)malloc(boardSize * sizeof(int*));
    for (int i = 0; i < boardSize; i++) {
        visited[i] = (int*)calloc(boardColSize[i], sizeof(int));
    }

    int cnt = 0;
    for (int i=0; i<boardSize; i++) {
        for (int j=0; j<boardColSize[i]; j++) {
            if (visited[i][j] == 0 && board[i][j] == 'X') {
                dfs_util(i, j, boardSize, boardColSize[i], board, visited);
                cnt++;
            }
        }
    }

    for (int i = 0; i < boardSize; i++) free(visited[i]);
    free(visited);

    return cnt;
}

int main() {
    int boardSize = 3;
    char boardData[3][4] = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
    char* board[3];
    for (int i=0; i<3; i++) board[i] = boardData[i];
    int boardColSize[3] = {4, 4, 4};
    printf("%d\n", countBattleships(board, boardSize, boardColSize));

    return 0;
}