#include <stdio.h>

int countBattleships(char** board, int boardSize, int* boardColSize) {
    int count = 0;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            // Count only the top-left corner of each battleship
            if (board[i][j] == 'X') {
                if (i > 0 && board[i-1][j] == 'X') continue; // Check above
                if (j > 0 && board[i][j-1] == 'X') continue; // Check left
                count++;
            }
        }
    }
    return count;
}

// Example usage
int main() {
    char* board[] = {
        "X..X",
        "...X",
        "...X"
    };
    int boardColSize[] = {4, 4, 4};
    printf("%d\n", countBattleships(board, 3, boardColSize)); // Output: 2
    return 0;
}
