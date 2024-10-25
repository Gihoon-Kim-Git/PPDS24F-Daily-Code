#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
public:
    vector<int> q;
    int capacity;
    int size;
    int front;
    int rear;

    MyCircularDeque(int k) {
        q = vector<int>(k, 0);  // Initialize the deque with size k
        capacity = k;
        size = 0;
        front = 0;
        rear = k - 1;  // Rear starts from the last position of the vector
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;  // Circular wrap-around for front
        q[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;  // Circular wrap-around for rear
        q[rear] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;  // Move front forward, circular wrap-around
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;  // Move rear backward, circular wrap-around
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return q[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};