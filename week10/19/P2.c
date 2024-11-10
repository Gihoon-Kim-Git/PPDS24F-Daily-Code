#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool stoneGameIX(int* stones, int stonesSize) {
    int stoneCount[3] = {0, 0, 0}; // {0, 1, 2} 모듈로 결과에 따라 돌을 세는 배열

    for (int i = 0; i < stonesSize; i++) {
        int num = stones[i] % 3;
        stoneCount[num]++;
    }

    if (stoneCount[0] % 2 == 0) {
        if (stoneCount[1] > 0 && stoneCount[2] > 0) return true;
        else return false;
    } else {
        if (abs(stoneCount[1] - stoneCount[2]) > 2) return true;
        else return false;
    }
}

int main() {
    int stones[] = {2,2,2,0};
    printf("%d\n", stoneGameIX(stones, 4));
    
    return 0;
}