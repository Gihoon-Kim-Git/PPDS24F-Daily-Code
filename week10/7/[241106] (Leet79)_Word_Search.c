#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(char** board, int i, int j, int boardSize, int* boardColSize, char* word, int **visited){
        if (*word == '\0'){
        return true;
    }

    // 범위 설정에 유의! 아니면 에러난다고!
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize[i] || visited[i][j] || board[i][j] != *word){
        return false;
    }

    visited[i][j] = 1;

    bool result = dfs(board, i-1, j, boardSize, boardColSize, word+1, visited) ||
                dfs(board, i+1, j, boardSize, boardColSize, word+1, visited) ||
                dfs(board, i, j-1, boardSize, boardColSize, word+1, visited) ||
                dfs(board,i, j+1, boardSize, boardColSize, word+1, visited);                    
    visited[i][j] = 0; // 다시 초기화를 해주어야 함에 유의 (이 함수가 끝나면 이전 호출단계로 넘어가는것이므로)

    return result;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {

    int** visited = (int**)malloc(boardSize * sizeof(int*));

    for (int i = 0; i < boardSize; ++i) {
        visited[i] = (int*)malloc(boardColSize[0] * sizeof(int));
        for (int j = 0; j < boardColSize[0]; ++j) {
            visited[i][j] = 0;  
        }
    }
    for (int i = 0 ; i < boardSize; ++i){
        for (int j= 0; j < boardColSize[0]; ++j){ //j가 boardColSize[i] 임에 유의
            if (dfs(board, i, j, boardSize, boardColSize, word, visited)){
                
                for (int k = 0; k < boardSize; ++k) {
                    free(visited[k]);
                }                
                free(visited);
                return true;
            }
        }
    }

    for (int k = 0; k < boardSize; ++k) {
        free(visited[k]);
    }
    free(visited);
    return false;
}