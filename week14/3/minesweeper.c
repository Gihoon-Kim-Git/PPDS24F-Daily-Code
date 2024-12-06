#include <stdio.h>
#include <stdlib.h>

// 8방향 이동을 위한 배열
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

// 보드 내 유효한 좌표인지 확인하는 함수
int isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// 현재 위치 주변에 있는 지뢰 수를 계산하는 함수
int countMines(char** board, int x, int y, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, rows, cols) && board[nx][ny] == 'M') {
            count++;
        }
    }
    return count;
}

// DFS를 사용하여 보드 상태를 업데이트하는 함수
void dfs(char** board, int x, int y, int rows, int cols) {
    // 주변 지뢰 수 계산
    int mines = countMines(board, x, y, rows, cols);
    
    if (mines > 0) {
        // 주변에 지뢰가 있으면 숫자로 업데이트
        board[x][y] = '0' + mines;
    } else {
        // 주변에 지뢰가 없으면 'B'로 업데이트
        board[x][y] = 'B';
        // 8방향으로 탐색
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny, rows, cols) && board[nx][ny] == 'E') {
                dfs(board, nx, ny, rows, cols);
            }
        }
    }
}

// 보드를 업데이트하는 메인 함수
char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes) {
    int rows = boardSize;
    int cols = *boardColSize;
    int x = click[0];
    int y = click[1];

    if (board[x][y] == 'M') {
        // 클릭한 위치가 지뢰이면 게임 오버 처리
        board[x][y] = 'X';
    } else if (board[x][y] == 'E') {
        // 클릭한 위치가 빈 칸이면 DFS를 통해 주변 탐색
        dfs(board, x, y, rows, cols);
    }

    // 결과 크기와 컬럼 크기를 반환하기 위한 설정
    *returnSize = rows;
    *returnColumnSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        (*returnColumnSizes)[i] = cols;
    }

    return board;
}

// 테스트용 메인 함수
int main() {
    // 테스트 보드 초기화
    char* board[] = {
        "EEEEE",
        "EEMEE",
        "EEEEE",
        "EEEEE"
    };

    int boardSize = 4;
    int boardColSize = 5;
    int click[] = {3, 0};

    // 결과 반환을 위한 변수
    int returnSize;
    int* returnColumnSizes;

    // 보드 업데이트 실행
    char** updatedBoard = updateBoard(board, boardSize, &boardColSize, click, 2, &returnSize, &returnColumnSizes);

    // 결과 출력
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%c ", updatedBoard[i][j]);
        }
        printf("\n");
    }

    free(returnColumnSizes); // 동적 메모리 해제

    return 0;
}
