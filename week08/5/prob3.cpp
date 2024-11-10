#include <vector>
using namespace std;

class MyCircularDeque {
private:
    int capacity;
    vector<int> vals;
    int begin = 0;
    int end = 0;

public:
    MyCircularDeque(int k) {
        capacity = k;
        vals = vector<int>(k+1);
    }
    
    bool insertFront(int value) {
        // cout << begin << end << endl;
        if (isFull()) return false;
        else {
            begin = (begin - 1 + capacity + 1) % (capacity + 1);
            vals.at(begin) = value;
            return true;
        }
    }
    
    bool insertLast(int value) {
        // cout << begin << end << endl;
        if (isFull()) return false;
        else {
            vals.at(end) = value;
            end = (end + 1) % (capacity + 1);
            return true;
        }
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        else {
            begin = (begin + 1) % (capacity + 1);
            return true;
        }
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        else {
            end = (end - 1 + capacity + 1) % (capacity + 1);
            return true;
        }
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        else return vals.at(begin);
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        // else {
        //     cout << begin << " " << end << " " << (end - 1 + capacity + 1) % (capacity + 1) << endl;
        //     return vals.at((end - 1 + capacity + 1) % (capacity + 1));
        // }
        else return vals.at((end - 1 + capacity + 1) % (capacity + 1));
    }
    
    bool isEmpty() {
        if (begin == end) return true;
        else return false;
    }
    
    bool isFull() {
        if ((end - begin + capacity + 1) % (capacity + 1) == capacity) return true;
        else return false;
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
