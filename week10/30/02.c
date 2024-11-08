
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool stoneGameIX(int* stones, int stonesSize) {
    int modCount[3] = {0, 0, 0};

    // (1) 돌을 3으로 나눈 나머지에 따라 개수를 세기
    for (int i = 0; i < stonesSize; i++) {
        modCount[stones[i] % 3]++;
    }

    // (2) mod0 돌의 개수가 짝수일 때와 홀수일 때를 구분하여 처리
    if (modCount[0] % 2 == 0) {
        // mod0이 짝수인 경우: mod1 또는 mod2 둘 중 하나라도 있으면 Alice가 승리 가능
        return modCount[1] > 0 && modCount[2] > 0;
    } else {
        // mod0이 홀수인 경우: mod1과 mod2 중 하나가 다른 것보다 2개 이상 많아야 Alice가 승리
        return abs(modCount[1] - modCount[2]) > 2;
    }
}

int main() {
    // int mySize = 2;
    // int* myStones = (int*)malloc(mySize * sizeof(int));
    // myStones[0] = 2; myStones[1] = 1;
 
    // int mySize = 1;
    // int* myStones = (int*)malloc(mySize * sizeof(int));
    // myStones[0] = 2; 

    // int mySize = 5;
    // int* myStones = (int*)malloc(mySize * sizeof(int));
    // myStones[0] = 5; myStones[1] = 1; myStones[2] = 2; myStones[4] = 4; myStones[3] =3; 
    // int mySize = 2;
    // int* myStones = (int*)malloc(mySize * sizeof(int));
    // myStones[0] = 3; myStones[1] = 3; 

    int mySize = 9;
    int* myStones = (int*)malloc(mySize * sizeof(int));
    myStones[0] = 20; myStones[1] = 3; myStones[2] = 20; 
    myStones[3] = 17; myStones[4] = 2; myStones[5] = 12; 
    myStones[6] = 15; myStones[7] = 17; myStones[8] = 4; 

    printf("%s", stoneGameIX(myStones, mySize) == 1 ? "true":"false");
    free(myStones);
    return 0;
}