#include <stdio.h>
#include <stdlib.h>

// Max heap structure
typedef struct {
    int* data;
    int size;
    int capacity;
} MaxHeap;

// Function prototypes
MaxHeap* createMaxHeap(int capacity);
void freeMaxHeap(MaxHeap* heap);
void push(MaxHeap* heap, int value);
int pop(MaxHeap* heap);
int top(MaxHeap* heap);
void maxHeapify(MaxHeap* heap, int i);

// Create a max heap with given capacity
MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// Free the max heap
void freeMaxHeap(MaxHeap* heap) {
    free(heap->data);
    free(heap);
}

// Push an element into the max heap
void push(MaxHeap* heap, int value) {
    if (heap->size >= heap->capacity) {
        printf("Heap is full!\n");
        return;
    }
    heap->data[heap->size] = value;
    int i = heap->size;
    heap->size++;

    // Bubble up to maintain heap property
    while (i > 0 && heap->data[i] > heap->data[(i - 1) / 2]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Pop the top element from the max heap
int pop(MaxHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    int topValue = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    // Heapify to maintain heap property
    maxHeapify(heap, 0);

    return topValue;
}

// Return the top element of the max heap
int top(MaxHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    return heap->data[0];
}

// Heapify the max heap at index i
void maxHeapify(MaxHeap* heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[largest];
        heap->data[largest] = temp;
        maxHeapify(heap, largest);
    }
}

// Last stone weight function
int lastStoneWeight(int* stones, int stonesSize) {
    MaxHeap* heap = createMaxHeap(stonesSize);

    // Add stones to the max heap
    for (int i = 0; i < stonesSize; i++) {
        push(heap, stones[i]);
    }

    // Simulate the stone smashing process
    while (heap->size > 1) {
        int first = pop(heap);
        int second = pop(heap);
        if (first > second) {
            push(heap, first - second);
        }
    }

    int result = heap->size > 0 ? top(heap) : 0;

    freeMaxHeap(heap);
    return result;
}

int main() {
    int stones1[] = {2, 7, 4, 1, 8, 1};
    int stonesSize1 = sizeof(stones1) / sizeof(stones1[0]);
    printf("%d\n", lastStoneWeight(stones1, stonesSize1));

    int stones2[] = {1};
    int stonesSize2 = sizeof(stones2) / sizeof(stones2[0]);
    printf("%d\n", lastStoneWeight(stones2, stonesSize2));

    return 0;
}