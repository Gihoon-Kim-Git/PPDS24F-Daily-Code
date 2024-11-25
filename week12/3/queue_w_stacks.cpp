#include <stack>
#include <stdexcept> // For runtime_error exceptions

class MyQueue {
    // first-in-first-out (FIFO) queue using only two stacks (LIFO)
    // use only standard operations of a stack,
    // which means only push to top, peek/pop from top, size, and is empty operations are valid
    // https://www.geeksforgeeks.org/queue-using-stacks/
    /*
    IDEA
    1. Use two stacks: stack1 (for enqueue operations) and stack2 (for dequeue operations).
    2. Push operations are always performed on stack1.
    3. For pop or peek operations:
       - If stack2 is empty, move all elements from stack1 to stack2.
       - This ensures that the front of the queue is always at the top of stack2.
    */

private:
    std::stack<int> s1; // Stack to handle push operations (enqueue)
    std::stack<int> s2; // Stack to handle pop and peek operations (dequeue)

public:
    MyQueue() {
        // Constructor: Initializes the queue with empty stacks
    }
    
    void push(int x) {
        // Push element x to the back of the queue
        // simply push element to stack 1
        s1.push(x);
        // e.g. myQueue->push(1); myQueue->push(2); myQueue->push(3);
        // q1: [1, 2, 3] (bottom to top), q2: []
    }
    
    int pop() {
        // Remove the element from the front of the queue and returns it
        // Step 1: If stack2 is empty, transfer all elements from stack1 to stack2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop(); // remove transferred element from stack1
            }
        }
        // After transferring:
        // s1: [] (all elements are moved)
        // s2: [3, 2, 1] (bottom to top, the front of the queue is at the top)
    
        // Step 2: If stack2 is still empty after the transfer, the queue is empty
        if (s2.empty()) {
            throw std::runtime_error("Queue is empty!");
        }

        // Step 3: Pop the top of stack2 (which represents the front of the queue)
        int frontElement = s2.top();
        s2.pop();
        return frontElement;
    }
    
    int peek() {
        // Return the element at the front of the queue (no removal)
        // Step 1: If stack2 is empty, transfer all elements from stack1 to stack2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop(); // remove transferred element from stack1
            }
        }
        // After transferring:
        // s1: [] (all elements are moved)
        // s2: [3, 2, 1] (bottom to top, the front of the queue is at the top)

        // Step 2: If stack2 is still empty after the transfer, the queue is empty
        if (s2.empty()) {
            throw std::runtime_error("Queue is empty!");
        }

        // Step 3: Return the top of stack2 (which represents the front of the queue)
        return s2.top();
    }
    
    bool empty() {
        // Return true if the queue is empty, false otherwise
        // The queue is empty only if both stacks are empty
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

#include <iostream>
int main() {
    MyQueue* myQueue = new MyQueue();

    myQueue->push(1); // Queue: [1]
    myQueue->push(2); // Queue: [1, 2]
    std::cout << "Front element: " << myQueue->peek() << std::endl; // Output: 1
    std::cout << "Removed element: " << myQueue->pop() << std::endl; // Output: 1, Queue: [2]
    std::cout << "Is queue empty? " << (myQueue->empty() ? "Yes" : "No") << std::endl; // Output: No

    delete myQueue; // Clean up dynamically allocated memory
    return 0;
}
/*
0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week12 (main)
$ g++ queue_w_stacks.cpp -o qws

0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week12 (main)
$ ./qws
Front element: 1
Removed element: 1
Is queue empty? No
*/