#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Pair;

void surroundingMines(char **board, int rows, int cols, int row, int col) {
    int i, j, count = 0;
    for (i = row-1; i <= row+1; ++i) {
        if (i >= 0 && i < rows) {
            for(j = col-1; j <= col+1; ++j) {
                if(j >= 0 && j < cols && board[i][j] == 'M') {
                    ++count;
                }
            }
        }
    }
    if (count == 0) {
        board[row][col] = 'B';
    } else {
        board[row][col] = count + '0';
    }
}

void bfs(char **board, int rows, int cols, int row, int col) {
    Pair queue[rows * cols];
    int i, j, head = 0, tail = 0;
    
    /* prime the queue */
    queue[tail].x = row;
    queue[tail].y = col;
    ++tail;

    /* repeat until queue is empty */
    while (head < tail) {
        row = queue[head].x;
        col = queue[head].y;
        ++head;
        surroundingMines(board, rows, cols, row, col);
        if (board[row][col] != 'B') {
            continue;
        }
        for (i = row-1; i <= row+1; ++i) {
            if (i >= 0 && i < rows) {
                for (j = col-1; j <=col+1; ++j) {
                    if (j >= 0 && j < cols && board[i][j] == 'E') {
                        board[i][j] = 'F'; /* dont visit again */
                        queue[tail].x = i;
                        queue[tail].y = j;
                        ++tail;
                    }
                }
            }
        }
    }
}

char **updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){
    int i = click[0], j = click[1];
    if (board[i][j] == 'M') {
        board[i][j] = 'X';
    } else { 
        bfs(board, boardSize, *boardColSize, i, j);
    }
    *returnSize = boardSize;
    *returnColumnSizes = boardColSize;
    return board;
}

int main() {
    // 보드 크기와 데이터 정의
    int boardSize = 4;
    int boardColSize[] = {5, 5, 5, 5};
    char* boardData[] = {
        "EEEEE",
        "EEMEE",
        "EEEEE",
        "EEEEE"
    };

    // 동적 2차원 배열 할당
    char** board = (char**)malloc(boardSize * sizeof(char*));
    for (int i = 0; i < boardSize; i++) {
        board[i] = (char*)malloc((boardColSize[i] + 1) * sizeof(char));
        snprintf(board[i], boardColSize[i] + 1, "%s", boardData[i]);
    }

    // 클릭 위치 정의
    int click[] = {3, 0};
    int clickSize = 2;

    // 반환값 정의
    int returnSize;
    int* returnColumnSizes;

    // 함수 호출
    char** updatedBoard = updateBoard(board, boardSize, boardColSize, click, clickSize, &returnSize, &returnColumnSizes);

    // 결과 출력
    printf("Updated Board:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%c ", updatedBoard[i][j]);
        }
        printf("\n");
    }

    // 동적 메모리 해제
    for (int i = 0; i < boardSize; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}