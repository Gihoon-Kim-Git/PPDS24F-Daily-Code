#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Pair 구조체 정의
typedef struct {
    int first;  // 종료 시간
    int second; // 승객 수
} Pair;

// Min-Heap 구조체 정의
typedef struct {
    Pair* data;
    int size;
    int capacity;
} MinHeap;

// Min-Heap 초기화
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (Pair*)malloc(capacity * sizeof(Pair));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// Min-Heap 정리 함수
void heapify(MinHeap* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->data[left].first < heap->data[smallest].first)
        smallest = left;

    if (right < heap->size && heap->data[right].first < heap->data[smallest].first)
        smallest = right;

    if (smallest != i) {
        Pair temp = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = temp;
        heapify(heap, smallest);
    }
}

// Min-Heap 삽입
void push(MinHeap* heap, Pair value) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow!\n");
        return;
    }

    heap->data[heap->size] = value;
    int i = heap->size;
    heap->size++;

    while (i != 0 && heap->data[(i - 1) / 2].first > heap->data[i].first) {
        Pair temp = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Min-Heap 최상위 요소 제거
Pair pop(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap underflow!\n");
        return (Pair){-1, -1};
    }

    Pair root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// Min-Heap 최상위 요소 가져오기
Pair top(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        return (Pair){-1, -1};
    }
    return heap->data[0];
}

// Min-Heap 메모리 해제
void freeMinHeap(MinHeap* heap) {
    free(heap->data);
    free(heap);
}

// Compare 함수 for qsort
int compare(const void* a, const void* b) {
    int* tripA = *(int**)a;
    int* tripB = *(int**)b;
    return tripA[1] - tripB[1]; // 시작 시간 기준 오름차순 정렬
}

// Car pooling 함수
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    int maxval = 0;
    // trips 정렬
    qsort(trips, tripsSize, sizeof(int*), compare);

    // Min-Heap 생성
    MinHeap* minHeap = createMinHeap(tripsSize);

    for (int i = 0; i < tripsSize; i++) {
        // 종료된 여행 제거
        while (minHeap->size > 0 && top(minHeap).first <= trips[i][1]) {
            maxval -= top(minHeap).second;
            pop(minHeap);
        }

        // 현재 여행 추가
        push(minHeap, (Pair){trips[i][2], trips[i][0]});
        maxval += trips[i][0];

        // 용량 초과 체크
        if (maxval > capacity) {
            freeMinHeap(minHeap);
            return false;
        }
    }

    freeMinHeap(minHeap);
    return true;
}

int main() {
    int trips1Data[][3] = {{2, 1, 5}, {3, 3, 7}};
    int* trips1[] = {trips1Data[0], trips1Data[1]};
    int trips1ColSize[] = {3, 3};
    int capacity1 = 4;
    printf("%d\n", carPooling(trips1, 2, trips1ColSize, capacity1)); // Output: 0 (False)

    int trips2Data[][3] = {{2, 1, 5}, {3, 5, 7}};
    int* trips2[] = {trips2Data[0], trips2Data[1]};
    int trips2ColSize[] = {3, 3};
    int capacity2 = 5;
    printf("%d\n", carPooling(trips2, 2, trips2ColSize, capacity2)); // Output: 1 (True)

    int trips3Data[][3] = {{2, 1, 5}, {3, 3, 7}, {4, 6, 9}};
    int* trips3[] = {trips3Data[0], trips3Data[1], trips3Data[2]};
    int trips3ColSize[] = {3, 3, 3};
    int capacity3 = 6;
    printf("%d\n", carPooling(trips3, 3, trips3ColSize, capacity3)); // Output: 0 (False)

    return 0;
}