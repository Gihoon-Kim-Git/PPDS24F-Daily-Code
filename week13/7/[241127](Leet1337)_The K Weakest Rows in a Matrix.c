/*You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
*/
/*Constraints:
    m == mat.length
    n == mat[i].length
    2 <= n, m <= 100
    1 <= k <= m
    matrix[i][j] is either 0 or 1.*/

/*수도코드
목표 : minPriority_Queue에 sum(row)를 priority로 넣고, eleme에는 index를 넣고, K개를 뽑음. 
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
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

    // if (left <= pq->heap_size && pq->heap[left].priority < pq->heap[smallest].priority)
    //     smallest = left;

    // if (right <= pq->heap_size && pq->heap[right].priority < pq->heap[smallest].priority)
    //     smallest = right;

    //priority가 같은 경우에 elem을 기준으로 비교해서 heapq에 넣을 수 있도록 수정.
    if (left <= pq->heap_size && 
        (pq->heap[left].priority < pq->heap[smallest].priority ||
        (pq->heap[left].priority == pq->heap[smallest].priority && pq->heap[left].element < pq->heap[smallest].element)))
        smallest = left;

    if (right <= pq->heap_size && 
        (pq->heap[right].priority < pq->heap[smallest].priority ||
        (pq->heap[right].priority == pq->heap[smallest].priority && pq->heap[right].element < pq->heap[smallest].element)))
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


int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    // 1) minPriorityQueue 선언
    PriorityQueue pq;
    pq.capacity = matSize;
    pq.heap_size = 0;
    pq.heap = (Node*)malloc((pq.capacity + 1) * sizeof(Node));

    // 2) mat의 row를 돌면서, sum(row)는 priority로 index는 elem으로 넣음.
    for (int i = 0; i < matSize; i++){
        int sum_row = 0;
        for (int j = 0; j < (*matColSize); j++){
            sum_row = sum_row + mat[i][j];
        }
        enqueue(&pq, sum_row, i);
    }

    // 3) pq에서 k개의 요소를 빼서 answre에 넣고, 반환.
    int* answer = (int*)malloc(sizeof(int)* k);
    int answer_index = 0;
    *returnSize = k;

    for (int m = 0; m < k ; m++){
        int cur = dequeue(&pq);
        answer[answer_index++] = cur;
    }

    clear(&pq);
    return answer;
}