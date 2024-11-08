#include <stdio.h>
#include <stdlib.h>

// n개의 의자 (0 ~ n-1)가 있고
// 젤 멀리 떨어져있는 곳에 앉기.
// (여러개면 젤 idx 낮은곳에 앉음)
// 아무도 없으면 0번에 앉겠지.

// 전략
// GREEDY 그냥 젤 가까운 idx까지의 거리를 확인하고 그 중 젤 max인 idx 고르기로 가보자. 

typedef struct {
    int seatN;
    int* chairs;    
} ExamRoom;


ExamRoom* examRoomCreate(int n) {
    ExamRoom* theRoom = (ExamRoom*)malloc(sizeof(ExamRoom));
    int* theChairs = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n ; i++) {
        theChairs[i] = 0;
    }

    theRoom->seatN = n;
    theRoom->chairs = theChairs;

    return theRoom;
}


int examRoomSeat(ExamRoom* obj) {
//CHECK 앉히기 전 의자 살펴보기.
// printf("\nStart\n");
    int n = obj->seatN;
//     for (int i = 0; i < n ; i++) {
//         printf("%d ", obj->chairs[i]);
//     }
// printf("\n");
//어떤 idx에 앉아야할지 return
// 전략
    // obj->chairs[0] = 1;
    // obj->chairs[5] = 1;
// 4 0 1 1 0 4 0 1 2 3
// 1 0 0 0 0 1 0 0 0 0 
// 0 1 2 2 1 0 1 2 3 4

// 그냥 젤 가까운 idx까지의 거리를 확인하고 그 중 젤 max인 idx 고르기로 가보자. 
// (1). 해당 idx에 앉았을때 젤 가까운 1까지의 거리를 기록한 array를 만들쟝
    int whatif[n];
    for (int i = 0; i < n ; i++) {
        whatif[i] = -1;
    }

// (2). greedy하게 array를 채우자. what if i에 앉는다면 closest person까지 거리가 얼마?
    for (int i = 0; i < n ; i++) {
        // printf("\n%d :", i);
        //만약 내가 1이면 거리 0인거고
        if (obj->chairs[i] == 1) {
            whatif[i] = 0;
        } else { //내가 1이 아니면 다른 거리로 바꿔
            int a = i; //왼쪽으로 쭉쭉
            int b = i; //오른쪽으로 쭉쭉
            int dist = 0;
            while ((a>=0) || (b <= n-1)) { //a랑 b둘중에 하나라도 범위안에 있으면. 
                // printf("a: %d, b: %d ", a, b);
                if (a < 0) { //b만 보기
                    if (obj->chairs[b] == 1) {
                        whatif[i] = dist;
                        break;
                    } else {
                        dist++; b++;
                    }    
                } else if (b > n-1) { //a만 보기
                    if (obj->chairs[a] == 1) {
                        whatif[i] = dist;
                        break;
                    } else {
                        dist++; a--;
                    }
                } else { //둘다 보기
                    if ((obj->chairs[a] == 1)||(obj->chairs[b] == 1)) {
                        whatif[i] = dist;
                        // printf("a: %d, b: %d", a, b);
                        break;
                    } else {
                        dist++; a--; b++;
                    }
                }

            }
        // printf("%d", dist);
        }

    }

// (3). array에서 제일 먼 idx에 앉을거야!! 그거 return
    int max_dist = 0;
    int max_idx = 0;
// printf("Dist\n");
    for (int i = 0; i < n ; i++) {
        // printf("%d ", whatif[i]);
        if (whatif[i] > max_dist) {
            max_idx = i;
            max_dist = whatif[i];
        };
    }

// (4). 앉혀!!
    // printf(" max idx = %d", max_idx);
    obj->chairs[max_idx] = 1;

// //CHECK 앉힌 후 의자 살펴보기.
// printf("\n");
//     for (int i = 0; i < n ; i++) {
//         printf("%d ", obj->chairs[i]);
//     }
// printf("\nEnd\n______");

    return max_idx;
}

void examRoomLeave(ExamRoom* obj, int p) {
    obj->chairs[p] = 0;
    return;
}

void examRoomFree(ExamRoom* obj) {
    int n = obj->seatN;
    free(obj->chairs);
    free(obj);
}

int main() {
    int n = 10;
    int p = 4;


    ExamRoom* obj = examRoomCreate(n);
    int param_1 = examRoomSeat(obj);
    int param_2 = examRoomSeat(obj);
    int param_3 = examRoomSeat(obj);
    int param_4 = examRoomSeat(obj);

    printf("%d\n", param_1);
    printf("%d\n", param_2);
    printf("%d\n", param_3);
    printf("%d\n", param_4);


 
    examRoomLeave(obj, p);
    int param_5 = examRoomSeat(obj);
    printf("%d\n", param_5);


    examRoomFree(obj);


    return 0;
}