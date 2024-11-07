#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int directions[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
bool visited[MAX_ROWS][MAX_COLS];

bool find_util(char** board, int boardSize, int* boardColSize, char* word, int row, int col, int index) {
    int n_row = boardSize;
    int n_col = *boardColSize;
    
    if (index == strlen(word) - 1) {
        return true;
    }
    
    visited[row][col] = true;
    
    for (int d = 0; d < 4; d++) {
        int new_row = row + directions[d][0];
        int new_col = col + directions[d][1];
        
        if (new_row >= 0 && new_row < n_row && new_col >= 0 && new_col < n_col &&
            !visited[new_row][new_col] && board[new_row][new_col] == word[index + 1]) {
            if (find_util(board, boardSize, boardColSize, word, new_row, new_col, index + 1)) {
                return true;
            }
        }
    }
    
    visited[row][col] = false;
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int n_row = boardSize;
    int n_col = *boardColSize;
    
    memset(visited, false, sizeof(visited));
    
    for (int i = 0; i < n_row; i++) {
        for (int j = 0; j < n_col; j++) {
            if (board[i][j] == word[0]) {
                if (find_util(board, boardSize, boardColSize, word, i, j, 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    char* board[] = {
        "ABCE",
        "SFCS",
        "ADEE"
    };
    int boardSize = 3;
    int boardColSize[] = {4, 4, 4};
    printf("%d\n", exist(board, boardSize, boardColSize, "ABCCED"));

    return 0;
}