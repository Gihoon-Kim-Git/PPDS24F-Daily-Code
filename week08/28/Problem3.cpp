#include <vector>

using namespace std;

class MyCircularDeque {
public:
    int front, end, capacity, size;
    vector<int> deque;

    MyCircularDeque(int k) {
        front = end = -1;
        capacity = k;
        size = 0;
        deque = vector<int>(k,0);
    }
    
    bool insertFront(int value) {
        if(isFull()){return false;}
        if(isEmpty()){
            front = 0;
            end = 0;
        }
        else{
            front = (front-1+capacity) % capacity;
        }
        deque[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){return false;}
        if(isEmpty()){
            front = 0;
            end = 0;
        }
        else{
            end = (end+1) % capacity;
        }
        deque[end] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){return false;}
        if(front == end){
            front = -1;
            end = -1;
        }
        else{
            front = (front+1) % capacity;
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){return false;}
        if(front == end){
            front = -1;
            end = -1;
        }
        else{
            end = (end-1+capacity) % capacity;
        }
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){return -1;}
        return deque[front];
    }
    
    int getRear() {
        if(isEmpty()){return -1;}
        return deque[end];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */