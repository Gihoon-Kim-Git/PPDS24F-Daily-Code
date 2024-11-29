#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 비교 함수: from 위치(1번째 값)를 기준으로 오름차순 정렬
int ascending(const void* a, const void* b) {
    const int* tripA = *(const int**)a;
    const int* tripB = *(const int**)b;
    return tripA[1] - tripB[1];
}

// 정렬 함수
void custom_sort(int** arr, int size) {
    qsort(arr, size, sizeof(int*), ascending);
}

// Car Pooling 함수
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    // Step 1: trips를 출발 시간(from) 기준으로 정렬
    custom_sort(trips, tripsSize);

    // Step 2: 현재 각 도착 시간을 관리하기 위한 배열 생성
    int passengerChange[1001] = {0}; // 최대 좌표값이 1000까지라 가정

    // Step 3: 승객 태우기 및 내리기 정보 업데이트
    for (int i = 0; i < tripsSize; i++) {
        int passengers = trips[i][0];
        int from = trips[i][1];
        int to = trips[i][2];

        passengerChange[from] += passengers; // from에서 승객 탑승
        passengerChange[to] -= passengers;  // to에서 승객 하차
    }

    // Step 4: 시간 순서대로 승객 상태 시뮬레이션
    int currentPassengers = 0;
    for (int i = 0; i < 1001; i++) {
        currentPassengers += passengerChange[i];
        if (currentPassengers > capacity) {
            return false; // 용량 초과 시 false 반환
        }
    }

    return true; // 모든 승객을 태우고 내리는 동안 용량 초과가 없으면 true
}

int main() {
    int capac1 = 4;
    int tripsSize1 = 2;
    int trips1_temp[][3] = {
        {2, 1, 5},
        {3, 3, 7}
    };
    int** trips1 = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        trips1[i] = trips1_temp[i];
    }

    int capac2 = 5;
    int tripsSize2 = 2;
    int trips2_temp[][3] = {
        {2, 1, 5},
        {3, 3, 7}
    };
    int** trips2 = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        trips2[i] = trips2_temp[i];
    }

    int capac3 = 11;
    int tripsSize3 = 3;
    int trips3_temp[][3] = {
        {3, 2, 8},
        {4, 4, 6},
        {10, 8, 9}
    };
    int** trips3 = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        trips3[i] = trips3_temp[i];
    }

    printf("ANS1: %s\n", carPooling(trips1, tripsSize1, NULL, capac1) ? "true" : "false");
    printf("ANS2: %s\n", carPooling(trips2, tripsSize2, NULL, capac2) ? "true" : "false");
    printf("ANS3: %s\n", carPooling(trips3, tripsSize3, NULL, capac3) ? "true" : "false");

    free(trips1);
    free(trips2);
    free(trips3);

    return 0;
}
