#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// // 전략
// // 1. boardData에 포함된 모든 시작 char에서 상하좌우 찾으며 단어가 있는지 없는지 확인한다.
// // 2. 단어가 발견되면 true를 return
// // 3. 발견 안되고 끝까지 갔으면 false return
bool search_4_dir(char** board, int boardSize, int* boardColSize, char* word, int i, int j, int** visited, int cur_pos) {
    // 경계 체크 및 방문 체크
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize[i] || visited[i][j] == 1 || board[i][j] != word[cur_pos]) {
        return false;
    }

    printf("%c ", board[i][j]);
    // 단어가 완성된 경우
    if (cur_pos == strlen(word) - 1) {
        return true;
    }

    // 현재 위치 방문 표시
    visited[i][j] = 1;

    // 다음 위치 탐색
    if (search_4_dir(board, boardSize, boardColSize, word, i + 1, j, visited, cur_pos + 1) ||
        search_4_dir(board, boardSize, boardColSize, word, i - 1, j, visited, cur_pos + 1) ||
        search_4_dir(board, boardSize, boardColSize, word, i, j + 1, visited, cur_pos + 1) ||
        search_4_dir(board, boardSize, boardColSize, word, i, j - 1, visited, cur_pos + 1)) {
        return true;
    }

    // 방문 해제 
    visited[i][j] = 0;

    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    char st_char = word[0];
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == st_char) {
                // 방문 체크할 visited 배열 초기화
                int** visited = (int**)malloc(boardSize * sizeof(int*));
                for (int k = 0; k < boardSize; k++) {
                    visited[k] = (int*)malloc(boardColSize[k] * sizeof(int));
                    for (int l = 0; l < boardColSize[k]; l++) {
                        visited[k][l] = 0;
                    }
                }

                // 현재 위치에서 탐색 시작
                if (search_4_dir(board, boardSize, boardColSize, word, i, j, visited, 0)) {
                    // 메모리 해제 후 결과 반환
                    for (int k = 0; k < boardSize; k++) {
                        free(visited[k]);
                    }
                    free(visited);
                    return true;
                }

                // 방문 배열 해제
                for (int k = 0; k < boardSize; k++) {
                    free(visited[k]);
                }
                free(visited);
            }
        }
    }
    return false;
}

int main() {
    char* boardData[] = {
        "ABCE",
        "SFCS",
        "ADEE"
    };

    int boardSize = 3;
    int boardColSize[] = {4, 4, 4};  // 각 행의 열 개수

    char** board = (char**)boardData;  // 2D 배열의 포인터로 사용

    char word[] = "ABCCED";

    printf("%s\n", exist(boardData, boardSize, boardColSize, word) ? "true" : "false");

    return 0;
}

