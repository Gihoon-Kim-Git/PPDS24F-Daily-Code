#include <queue>
#include <stdexcept> // for std::runtime_error

class MyStack {
    // last-in-first-out (LIFO) stack using only two queues (FIFO)
    // use only standard operations of a queue,
    // which means that only push to back, peek/pop from front, size and is empty operations are valid
    // https://www.geeksforgeeks.org/implement-stack-using-queue/
    /*
    IDEA
    keep newly entered element at the front of q1 so that pop operation dequeues from q1
    q2 is used to put every new element in front of q1
    */

private:
    std::queue<int> q1; // main queue to simulate the stack
    std::queue<int> q2; // temporary queue to help in stack operations

    // Custom swap function to exchange contents of q1 and q2
    void swapQueues(std::queue<int>& q1, std::queue<int>& q2) {
        // Temporarily hold elements from q2 and move them to q1
        std::queue<int> temp;
        while (!q1.empty()) {
            temp.push(q1.front());
            q1.pop();
        }
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        while (!temp.empty()) {
            q2.push(temp.front());
            temp.pop();
        }
    }

public:
    MyStack() {
        // Constructor: Initialize the stack
    }
    
    void push(int x) {
        // Push element x to the top of the stack
        // NEWLY PUSHED ELEMENT TO THE FRONT OF Q1 (= TOP of the Stack)
        
        // Step 1: Push the new element into the empty q2
        q2.push(x);
        // e.g. myStack->push(1); myStack->push(2);
        // q1: [1], q2: [2]

        // Step 2: Move all elements from q1 to q2
        // ensures that the newly added element is at the front of q2
        while (!q1.empty()) {
            q2.push(q1.front()); // front element of q1 moved to q2
            q1.pop();
        }
        // e.g. myStack->push(1); myStack->push(2);
        // q1: [], q2: [2, 1]

        // Step 3: Swap q1 and q2
        // q1 becomes the main queue again (contains the updated stack order)
        // std::swap(q1, q2);
        swapQueues(q1, q2);
        // e.g. myStack->push(1); myStack->push(2);
        // q1: [2, 1], q2: []
        // Stack (top -> bottom): [2, 1] (LIFO)
    }
    
    int pop() {
        // Remove the element on the top of the stack and returns it
        if (q1.empty()) {
            throw std::runtime_error("Stack is empty!");
        }
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
    
    int top() {
        // Return the element on the top of the stack
        if (q1.empty()) {
            throw std::runtime_error("Stack is empty!");
        }
        return q1.front();
    }
    
    bool empty() {
        // Return true if the stack is empty, false otherwise
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

#include <iostream>

int main() {
    MyStack* myStack = new MyStack();

    myStack->push(1);
    myStack->push(2);
    std::cout << "Top element: " << myStack->top() << std::endl; // Output: 2
    std::cout << "Popped element: " << myStack->pop() << std::endl; // Output: 2
    std::cout << "Is stack empty? " << (myStack->empty() ? "Yes" : "No") << std::endl; // Output: No
    return 0;
}
/*
0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week12 (main)
$ g++ stack_w_queues.cpp -o swq

0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week12 (main)
$ ./swq
Top element: 2
Popped element: 2
Is stack empty? No
*/