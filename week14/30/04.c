/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. M이 밝혀지면 -> X로 바꾼다.
// 2. E가 눌리면 
//     -> M이 팔방 반경 안에 있는 테두리까지 모두 B로 바꾸고, 그 테두리는  M의 개수 COUNT해서 그걸로 E를 대체한다.
//     --> 내가 E이고, 팔방중에 E인 애들로 뻗어나감 계속. E랑 접촉할 수 없을때까지 뻗어나감~

void printMatrix(char** board, int rowN, int colN) {
    for (int i = 0; i < rowN; i++) {
        for (int j = 0; j < colN; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\nFINISHED\n");
}


int isM(char** board, int rowN, int colN, int x, int y) {
    if ((x >= 0) && (x  < rowN) && (y >=0) && (y < colN)) {
        if (board[x][y] == 'M') {
            return 1;
        }
    }
    return 0;
}
int countM(char** board, int x, int y, int rowN, int colN, int** visited) {
    if ((x >= 0) && (x  < rowN) && (y >=0) && (y < colN)) {
        int cntM = 0;
        cntM+= isM(board, rowN, colN, x-1, y-1);
        cntM+= isM(board, rowN, colN, x-1, y);
        cntM+= isM(board, rowN, colN, x-1, y+1);
        cntM+= isM(board, rowN, colN, x, y-1);
        cntM+= isM(board, rowN, colN, x, y+1);
        cntM+= isM(board, rowN, colN, x+1, y-1);
        cntM+= isM(board, rowN, colN, x+1, y);
        cntM+= isM(board, rowN, colN, x+1, y+1);
        return cntM;
    }
    return 0;
}

void updateHelper(char** board, int x, int y, int rowN, int colN, int** visited) {
    if ((x >= 0) && (x  < rowN) && (y >=0) && (y < colN) &&(visited[x][y] == 0)) {
        if (board[x][y] == 'E') {
            //(1). x, y 방문을 해서 해야할일 일단 하기!
            visited[x][y] = 1;
            int cntM = countM(board, x, y, rowN, colN, visited);
            if (cntM == 0) {board[x][y] = 'B';}
            else {
                //cntM이 0이 아니면 그 값 넣어쥼!
                char cntMstr[2];                
                sprintf(cntMstr, "%d", cntM);
                board[x][y] = cntMstr[0];
            }
            if ((board[x][y] == 'B')) { //cnt update한 다음에도 B인 경우에만! 팔방 탐색
                // printf("(%d,%d): %c\n", x, y, board[x][y]);
                updateHelper(board, x-1, y-1, rowN, colN, visited);
                updateHelper(board, x-1, y, rowN, colN, visited);
                updateHelper(board, x-1, y+1, rowN, colN, visited);
                updateHelper(board, x, y-1, rowN, colN, visited);
                updateHelper(board, x, y+1, rowN, colN, visited);
                updateHelper(board, x+1, y-1, rowN, colN, visited);
                updateHelper(board, x+1, y, rowN, colN, visited);
                updateHelper(board, x+1, y+1, rowN, colN, visited);
            }
        } else if (board[x][y] == 'M') {
            board[x][y] = 'X';
        }

    } else {
        return;
    }
}

char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes) {
    int rowN = boardSize; int colN = boardColSize[0];
    int** visited = (int**)malloc(rowN * sizeof(int*));
    for (int i = 0; i < rowN; i++) {
        visited[i] = (int*)malloc(colN * sizeof(int));
        for (int j = 0; j < colN; j++) {
            visited[i][j] = 0;
        }
    }

    *returnSize = boardSize; // 보드의 행 개수 설정
    *returnColumnSizes = (int*)malloc(boardSize * sizeof(int)); // 각 행의 열 크기 설정
    for (int i = 0; i < boardSize; i++) {
        (*returnColumnSizes)[i] = boardColSize[i]; // 각 행의 열 크기 복사
    }

    updateHelper(board, click[0], click[1], boardSize, boardColSize[0], visited);

    for (int i = 0; i < rowN; i++) {
        free(visited[i]);
    }
    free(visited);

    return board;
}



int main() {
    char board1temp[][5] = {
    {'E','E','E','E','E'},
    {'E','E','M','E','E'},
    {'E','E','E','E','E'},
    {'E','E','E','E','E'}};
    int rowN1 = 4; int colN1 = 5; int boardColSize1[] = {5,5,5,5};
    char** board1 = (char**)malloc(rowN1 * sizeof(char*));
    for (int i = 0; i < rowN1; i++) {
        board1[i] = (char*)malloc(colN1 * sizeof(char));
        for (int j = 0; j < colN1; j++) {
            board1[i][j] = board1temp[i][j];
        }
    }
    // printMatrix(board1, rowN1, colN1);


    int click1[] = {3,0}; int clickSize1 = sizeof(click1)/sizeof(click1[0]);
    int* returnSize1 = (int*)malloc(sizeof(int));  // 동적 할당
    int* return1 = NULL;  // 포인터 초기화
    
    updateBoard(board1, rowN1, boardColSize1,click1, clickSize1, returnSize1, &return1);
    printf("______ANSWER1_______\n");
    printMatrix(board1, rowN1, colN1);

    free(returnSize1);
    free(return1);
    for (int i = 0; i < rowN1; i++) { free(board1[i]);}
    free(board1);



// click = {3,0} => output = {
//     {"B","1","E","1","B"},
//     {"B","1","M","1","B"},
//     {"B","1","1","1","B"},
//     {"B","B","B","B","B"}
// };
///////////////////////////////////////////////////////////////
    char board2temp[][5] = {
    {'B','1','E','1','B'},
    {'B','1','M','1','B'},
    {'B','1','1','1','B'},
    {'B','B','B','B','B'}
};
    int rowN2 = 4; int colN2 = 5; int boardColSize2[] = {5,5,5,5};
    char** board2 = (char**)malloc(rowN2 * sizeof(char*));
    for (int i = 0; i < rowN2; i++) {
        board2[i] = (char*)malloc(colN2 * sizeof(char));
        for (int j = 0; j < colN2; j++) {
            board2[i][j] = board2temp[i][j];
        }
    }
    int click2[] = {1,2}; int clickSize2 = sizeof(click2)/sizeof(click2[0]);

    int* returnSize2 = (int*)malloc(sizeof(int));  // 동적 할당
    int* return2 = NULL;  // 포인터 초기화
    updateBoard(board2, rowN2, boardColSize2, click2, clickSize2, returnSize2, &return2);
    printf("______ANSWER2_______\n");
    printMatrix(board2, rowN2, colN2);

    free(returnSize2);
    free(return2);
    for (int i = 0; i < rowN2; i++) { free(board2[i]);}
    free(board2);

// click = {1,2}
// Output: 
// {
//     {"B","1","E","1","B"},
//     {"B","1","X","1","B"},
//     {"B","1","1","1","B"},
//     {"B","B","B","B","B"}
// };
///////////////////////////////////////////////////////////////


    char board3temp[][5] = {
    {'E','E','E','E','E'},
    {'E','E','M','E','E'},
    {'E','E','E','E','E'},
    {'E','E','E','E','E'}
};
    int rowN3 = 4; int colN3 = 5; int boardColSize3[] = {5,5,5,5};
    char** board3 = (char**)malloc(rowN3 * sizeof(char*));
    for (int i = 0; i < rowN3; i++) {
        board3[i] = (char*)malloc(colN3 * sizeof(char));
        for (int j = 0; j < colN3; j++) {
            board3[i][j] = board3temp[i][j];
        }
    }

    int click3[] = {3,0}; int clickSize3 = sizeof(click3)/sizeof(click3[0]);
    int* returnSize3 = (int*)malloc(sizeof(int));  // 동적 할당
    int* return3 = NULL;  // 포인터 초기화
    updateBoard(board3, rowN3, boardColSize3, click3, clickSize3, returnSize3, &return3);
    printf("______ANSWER3_______\n");
    printMatrix(board3, rowN3, colN3);

    free(returnSize3);
    free(return3);
    for (int i = 0; i < rowN3; i++) { free(board3[i]);}
    free(board3);
    return 0;

// output = 
//     [
//     ["B","1","E","1","B"],
//     ["B","1","M","1","B"],
//     ["B","1","1","1","B"],
//     ["B","B","B","B","B"]]

}


