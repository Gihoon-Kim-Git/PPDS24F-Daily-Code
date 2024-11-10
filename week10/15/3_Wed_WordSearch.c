#include <stdbool.h>
#include <string.h>

bool dfs(char** board, int boardSize, int* boardColSize, char* word, int r, int c, int w, bool** visited) {
    
    if (w == strlen(word)) {
        return true;
    }
    
    if (r < 0 || c < 0 || r >= boardSize || c >= boardColSize[r] || board[r][c] != word[w] || visited[r][c]) {
        return false;
    }
    
    visited[r][c] = true;
    
    bool result = dfs(board, boardSize, boardColSize, word, r + 1, c, w + 1, visited) ||
                  dfs(board, boardSize, boardColSize, word, r, c + 1, w + 1, visited) ||
                  dfs(board, boardSize, boardColSize, word, r - 1, c, w + 1, visited) ||
                  dfs(board, boardSize, boardColSize, word, r, c - 1, w + 1, visited);

    visited[r][c] = false;

    return result;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    
    bool** visited = (bool**)malloc(boardSize * sizeof(bool*));
    for (int i = 0; i < boardSize; i++) {
        visited[i] = (bool*)malloc(boardColSize[i] * sizeof(bool));
        memset(visited[i], 0, boardColSize[i] * sizeof(bool));  
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (dfs(board, boardSize, boardColSize, word, i, j, 0, visited)) {
                
                for (int k = 0; k < boardSize; k++) {
                    free(visited[k]);
                }
                free(visited);
                return true;
            }
        }
    }
   
    for (int i = 0; i < boardSize; i++) {
        free(visited[i]);
    }
    free(visited);

    return false;
}