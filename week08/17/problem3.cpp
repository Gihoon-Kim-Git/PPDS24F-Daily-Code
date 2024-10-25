// Design your implementation of the circular double-ended queue (deque).

// Implement the MyCircularDeque class:

// MyCircularDeque(int k) Initializes the deque with a maximum size of k.
// boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
// boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
// int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
// int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
// boolean isEmpty() Returns true if the deque is empty, or false otherwise.
// boolean isFull() Returns true if the deque is full, or false otherwise.
 

// Example 1:

// Input
// ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
// [[3], [1], [2], [3], [4], [], [], [], [4], []]
// Output
// [null, true, true, true, false, 2, true, true, true, 4]

// Explanation
// MyCircularDeque myCircularDeque = new MyCircularDeque(3);
// myCircularDeque.insertLast(1);  // return True
// myCircularDeque.insertLast(2);  // return True
// myCircularDeque.insertFront(3); // return True
// myCircularDeque.insertFront(4); // return False, the queue is full.
// myCircularDeque.getRear();      // return 2
// myCircularDeque.isFull();       // return True
// myCircularDeque.deleteLast();   // return True
// myCircularDeque.insertFront(4); // return True
// myCircularDeque.getFront();     // return 4
 

// Constraints:

// 1 <= k <= 1000
// 0 <= value <= 1000
// At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.


#include <vector>

using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class MyCircularDeque {
public:

    Node* frontNode;
    Node* lastNode;
    int queueSize;
    int cnt;

    MyCircularDeque(int k) {

        this->frontNode = new Node(-1);
        this->lastNode = new Node(-1);
        this->frontNode->next = this->lastNode;
        this->lastNode->prev = this->frontNode;
        this->queueSize = k;
        this->cnt = 0;
    }
    
    bool insertFront(int value) {
        Node* newNode = new Node(value);
        if (this->cnt == this->queueSize){
            return false;
        }

        newNode->next = this->frontNode->next;
        newNode->prev = this->frontNode;
        
        this->frontNode->next->prev = newNode;
        this->frontNode->next = newNode;

        this->cnt++;

        return true;
    }
    
    bool insertLast(int value) {
        Node* newNode = new Node(value);
        if (this->cnt == this->queueSize){
            return false;
        }

        newNode->next = this->lastNode;
        newNode->prev = this->lastNode->prev;

        this->lastNode->prev->next = newNode;
        this->lastNode->prev = newNode;

        this->cnt++;

        return true;
    }
    
    bool deleteFront() {
        if (this->cnt == 0){
            return false;
        }

        Node* delNode = this->frontNode->next;

        this->frontNode->next = delNode->next;
        delNode->next->prev = this->frontNode;

        this->cnt--;

        return true;
    }
    
    bool deleteLast() {

        if (this->cnt == 0){
            return false;
        }

        Node* delNode = this->lastNode->prev;

        this->lastNode->prev = delNode->prev;
        delNode->prev->next = this->lastNode;

        this->cnt--;

        return true;
    }
    
    int getFront() {
        if (this->cnt == 0){
            return -1;
        }  
        return this->frontNode->next->val;
    }
    
    int getRear() {
        if (this->cnt == 0){
            return -1;
        }

        return this->lastNode->prev->val;
    }
    
    bool isEmpty() {
        return this->cnt == 0;  
    }
    
    bool isFull() {
        return this->cnt == this->queueSize;    
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