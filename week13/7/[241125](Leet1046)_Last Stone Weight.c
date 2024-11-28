/*You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is 
at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.
*/

/*Constraints:
    1 <= stones.length <= 30
    1 <= stones[i] <= 1000
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int priority;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} SortedLinkedListPQ;

void init(SortedLinkedListPQ* pq) {
    pq->head = NULL;
}

void enqueue(SortedLinkedListPQ* pq, int priority) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->priority = priority;
    new_node->next = NULL;

    if (pq->head == NULL || pq->head->priority < priority) {
        new_node->next = pq->head;
        pq->head = new_node;
    } else {
        Node* current = pq->head;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

int dequeue(SortedLinkedListPQ* pq) {
    if (pq->head == NULL) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    Node* temp = pq->head;
    pq->head = pq->head->next;
    int result = temp->priority;
    free(temp);
    return result;
}

int peek(SortedLinkedListPQ* pq) {
    if (pq->head == NULL) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    return pq->head->priority;
}

int size(SortedLinkedListPQ* pq) {
    int count = 0;
    Node* current = pq->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int is_empty(SortedLinkedListPQ* pq) {
    return pq->head == NULL;
}

void clear(SortedLinkedListPQ* pq) {
    Node* current = pq->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    pq->head = NULL;
}

int lastStoneWeight(int* stones, int stonesSize) {
    SortedLinkedListPQ pq;
    init(&pq);
    for (int i = 0; i < stonesSize; i++){
        enqueue(&pq, stones[i]);
    } 
    while (size(&pq) > 1){
        int bigger = dequeue(&pq);
        int smaller = dequeue(&pq);
        enqueue(&pq, bigger-smaller);
    }
    if (is_empty(&pq)) {
        clear(&pq);
        return 0;
    }
    else {
        int answer = dequeue(&pq);
        clear(&pq);
        return answer;
    }
}