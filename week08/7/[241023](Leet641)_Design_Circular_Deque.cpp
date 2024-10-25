/*"""문제
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
"""


"""Constraints
    1 <= k <= 1000
    0 <= value <= 1000
    At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.
"""*/

#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque {
    int max_len;
    vector<int> que;
public:
    MyCircularDeque(int k) {
        max_len = k;
        que = {};
    }
    
    bool insertFront(int value) {
        if (que.size() == max_len){
            return false;
        } else {
            que.insert(que.begin(), value); //시작 iterato에 value 삽입
            return true;
        }
    }
    
    bool insertLast(int value) {
        if (que.size() == max_len){
            return false;
        } else {
            que.push_back(value);
            return true;
        }
    }
    
    bool deleteFront() {
        if (que.size() == 0){
            return false;
        } else {
            que.erase(que.begin());
            return true;
        }
    }
    
    bool deleteLast() {
        if (que.size() == 0){
            return false;
        } else {
            que.pop_back(); // delete the last element
            return true;
        }
    }
    
    int getFront() {
        if (que.size() == 0){
            return -1;
        } else {
            return que[0]; 
        }
    }
    
    int getRear() {
        if (que.size() == 0){
            return -1;
        } else {
            return que.back(); // back() : 맨 마지막 element 반환
        }
    }
    
    bool isEmpty() {
        if (que.size() == 0){
            return true;
        } else {
            return false;
        }
    }
    
    bool isFull() {
        return que.size()== max_len ? true :false ;
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











