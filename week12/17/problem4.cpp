// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

// Implement the MyQueue class:

// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
// Notes:

// You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

#include <stack>

using namespace std;


 class MyQueue {
public:
    stack<int> s1; 
    stack<int> s2; 
    
    
    MyQueue() {

    }
    
    void push(int x) {

        this->s1.push(x);
        
    }
    
    int pop() {

        if (this->s2.empty()) {
            while (!this->s1.empty()) {
                this->s2.push(this->s1.top());
                this->s1.pop();
            }
        }

        int result = this->s2.top();
        this->s2.pop();

        return result;
        
    }
    
    int peek() {

        if (this->s2.empty()) {
            while (!this->s1.empty()) {
                this->s2.push(this->s1.top());
                this->s1.pop();
            }
        }

        return this->s2.top();
        
    }
    
    bool empty() {

        return this->s1.empty() && this->s2.empty();
        
    } 

              
};
