class MyCircularDeque {
    deque<int> deque;
    int size=0;
    int maxsize;
public:
    MyCircularDeque(int k) {
        maxsize = k;
    }
    
    bool insertFront(int value) {
        if (size == maxsize) {
            return false;
        }
        deque.push_front(value);
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (size == maxsize) {
            return false;
        }
        deque.push_back(value);
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (size == 0) {
            return false;
        }
        deque.pop_front();
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (size == 0) {
            return false;
        }
        deque.pop_back();
        size--;
        return true;
    }
    
    int getFront() {
        if (size==0) {
            return -1;
        } else {
            return deque.front();
        }
    }
    
    int getRear() {
        if (size==0) {
            return -1;
        } else {
            return deque.back();
        }
    }
    
    bool isEmpty() {
        if (size == 0) {
            return true;
        } else {
            return false;
        }
    }
    
    bool isFull() {
        if (size == maxsize) {
            return true;
        } else {
            return false;
        }
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