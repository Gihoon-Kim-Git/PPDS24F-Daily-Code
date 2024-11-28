/*There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.*/

/*Constraints:
    1 <= trips.length <= 1000
    trips[i].length == 3
    1 <= numPassengersi <= 100
    0 <= fromi < toi <= 1000
    1 <= capacity <= 105 */

/* 수도코드
목표 : trips를 from 시간을 기준으로 오름차순 정렬 후, trip을 순회하면서 minHeap에 차례로 넣고 조건따라 빼면서, cur_people을 관리하고, cur_people이 capacity보다 커지면 return False

1. trips를 from(trip[i][1])을 기준으로 오름차순 sort
2. trip을 순회하며 min_priority_queue에 삽입.
    이때 priority는 to(trip[i][2]), element는 numPassenger(trip[i][0])
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int priority; //
    int element;
} Node;

typedef struct {
    Node *heap;
    int capacity;
    int heap_size;
} PriorityQueue;

void min_heapify(PriorityQueue *pq, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= pq->heap_size && pq->heap[left].priority < pq->heap[smallest].priority)
        smallest = left;

    if (right <= pq->heap_size && pq->heap[right].priority < pq->heap[smallest].priority)
        smallest = right;

    if (smallest != i) {
        Node temp = pq->heap[i];
        pq->heap[i] = pq->heap[smallest];
        pq->heap[smallest] = temp;
        min_heapify(pq, smallest);
    }
}

void decrease_key(PriorityQueue *pq, int i, int priority, int elem) {
    if (priority > pq->heap[i].priority) {
        printf("New priority is bigger than current priority\n");
        return;
    }
    pq->heap[i].priority = priority;
    pq->heap[i].element = elem;
    while (i > 1 && pq->heap[i / 2].priority > pq->heap[i].priority) {
        Node temp = pq->heap[i];
        pq->heap[i] = pq->heap[i / 2];
        pq->heap[i / 2] = temp;
        i = i / 2;
    }
}

void enqueue(PriorityQueue *pq, int priority, int elem) {
    if (pq->heap_size == pq->capacity) {
        printf("Heap overflow\n");
        return;
    }
    pq->heap_size++;
    pq->heap[pq->heap_size].priority = INT_MAX;
    decrease_key(pq, pq->heap_size, priority, elem);
}

int dequeue(PriorityQueue *pq) {
    if (pq->heap_size == 0) {
        printf("Heap underflow\n");
        //return NULL; //만약 int를 뱉어야 하면 NULL은 안된다. char*일때만 작동함.
        return -1;
    }
    int min_value = pq->heap[1].element;
    pq->heap[1] = pq->heap[pq->heap_size];
    pq->heap_size--;
    min_heapify(pq, 1);
    return min_value;
}

int peek_priority(PriorityQueue *pq) {
    if (pq->heap_size == 0) {
        printf("Heap underflow\n");
        //return NULL; //만약 int를 뱉어야 하면 NULL은 안된다. char*일때만 작동함.
        return -1;
    }
    return pq->heap[1].priority;
}

int peek_elem(PriorityQueue *pq) {
    if (pq->heap_size == 0) {
        printf("Heap underflow\n");
        //return NULL; //만약 int를 뱉어야 하면 NULL은 안된다. char*일때만 작동함.
        return -1;
    }
    return pq->heap[1].element;
}

int size(PriorityQueue *pq) {
    return pq->heap_size;
}

bool is_empty(PriorityQueue *pq) {
    return pq->heap_size == 0;
}

void clear(PriorityQueue *pq) {
    pq->heap_size = 0;
}

int compare(const void *a, const void *b) {
    int *rowA = *(int **)a;
    int *rowB = *(int **)b;
    return rowA[1] - rowB[1];  // 두 번째 열을 기준으로 오름차순 정렬
}

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    // 1) trips를 trips[i][1] 기준으로 오름차순 정렬
    qsort(trips, tripsSize, sizeof(int*), compare);
    // 2) min_priority_queue와 cur_people 선언
    PriorityQueue pq;
    pq.capacity = tripsSize;
    pq.heap_size = 0;
    pq.heap = (Node*)malloc((pq.capacity + 1) * sizeof(Node));

    int cur_people = 0;

    // 3) trips을 순회하면서 pq에 넣기 (priority : trips[i][2], elem: trips[i][0])
    for (int i = 0; i < tripsSize; i++){
        enqueue(&pq, trips[i][2], trips[i][0]);
        cur_people += trips[i][0];
        int cur_top_to = peek_priority(&pq);
        while ( cur_top_to <= trips[i][1] ){
            int cur_top_passenger = dequeue(&pq);
            cur_people = cur_people - cur_top_passenger;
            cur_top_to = peek_priority(&pq);
        }
        if (cur_people > capacity) return false;
    }
    return true;
}