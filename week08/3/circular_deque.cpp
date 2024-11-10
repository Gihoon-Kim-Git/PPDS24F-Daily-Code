#include <iostream>
#include <vector>
using namespace std;

// circular double-ended queue (deque)
// ref. https://www.geeksforgeeks.org/implementation-deque-using-circular-array/
class MyCircularDeque {
public:
    // Constructor: initialize the deque with a maximum size of k
    MyCircularDeque(int k) {
        size = k; // set maximum size of deque
        deque.resize(k); // initialize deque with size k

        front = 0; // initialize front pointer
        rear = 0; // initialize rear pointer
        count = 0; // number of elements currently in deque
    }
    
    // Method to insert an item at the front of the deque
    bool insertFront(int value) {
        if (isFull()) {
            return false; // if deque is full, return false
        }
        /*
        front - 1: decreases the front pointer by 1, moving it backward.
        + size: adding size ensures that the result is non-negative. subtracting 1 from front might result in a negative value if front is at position 0.
        by adding size, we handle the case where front would wrap around to the end of the array.
        % size: ensures the front pointer stays within the bounds of the array.
        wraps the pointer around to the end if it becomes negative or exceeds the array size.
        */
        front = (front - 1 + size) % size; // move the front pointer backward in a circular manner
        deque[front] = value; // insert the value at new front position
        count++; // increment number of elements
        return true; // insertion succesful
    }
    
    // Method to insert an item at the rear of the deque
    bool insertLast(int value) {
        if (isFull()) {
            return false; // if deque is full, return false
        }
        deque[rear] = value; // insert the value at rear position
        /*
        rear + 1: increases the rear pointer by 1, moving it forward.
        % size: ensures the rear pointer wraps around to the beginning of the array when it reaches the end.
        if rear equals size - 1 (the last index of the array), adding 1 would wrap it around to 0.
        */
        rear = (rear + 1) % size; // move rear pointer forward in a circular manner
        count++;
        return true; // insertion successful
    }
    
    // Method to delete an item from the front of the deque
    bool deleteFront() {
        if (isEmpty()) {
            return false; // if deque is empty, return false
        }
        front = (front + 1) % size; // move the front pointer forward in a circular manner
        count--; // decrement number of elements
        return true; // deletion successful
    }
    
    // Method to delete an item from the rear of the deque
    bool deleteLast() {
        if (isEmpty()) {
            return false; // if deque is empty, return false
        }
        rear = (rear - 1 + size) % size; // move rear pointer backward in a circular manner
        count--; // decrement number of elements
        return true; // deletion successful
    }
    
    // Method to get the front item from the deque
    int getFront() {
        if (isEmpty()) {
            return -1; // if deque is empty, return -1
        }
        return deque[front]; // return value at the front pointer
    }
    
    // Method to get the last item from the deque
    int getRear() {
        if (isEmpty()) {
            return -1; // if deque is empty, return -1
        }
        return deque[(rear - 1 + size) % size]; // return value at the rear pointer (adjusted backward)
    }
    
    // Method to check if the deque is empty
    bool isEmpty() {
        return count == 0; // if number of elements is 0, deque is empty
    }
    
    // Method to check if the deque is full
    bool isFull() {
        return count == size; // if number of elements is equal to maximum size, deque is full
    }

private:
    std::vector<int> deque; // vector to store the elements of the deque
    int size; // maximum size of the deque
    int front; // pointer to the front of the deque
    int rear; // pointer to the rear of the deque
    int count; // number of elements currently in the deque
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

// Example usage
int main() {
    MyCircularDeque myCircularDeque(3);
    cout << myCircularDeque.insertLast(1) << endl;  // Output: 1 (true)
    cout << myCircularDeque.insertLast(2) << endl;  // Output: 1 (true)
    cout << myCircularDeque.insertFront(3) << endl; // Output: 1 (true)
    cout << myCircularDeque.insertFront(4) << endl; // Output: 0 (false), the deque is full
    cout << myCircularDeque.getRear() << endl;      // Output: 2
    cout << myCircularDeque.isFull() << endl;       // Output: 1 (true)
    cout << myCircularDeque.deleteLast() << endl;   // Output: 1 (true)
    cout << myCircularDeque.insertFront(4) << endl; // Output: 1 (true)
    cout << myCircularDeque.getFront() << endl;     // Output: 4
    return 0;
}

/*
0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week08 (main)
$ g++ circular_deque.cpp -o cdq

0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week08 (main)
$ ./cdq
1
1
1
0
2
1
1
1
4
*/

/*
PROBLEM
Line 1121: Char 34: runtime error: addition of unsigned offset to 0x502000000510 overflowed to 0x50200000050c (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/13/../../../../include/c++/13/bits/stl_vector.h:1126:34
*/