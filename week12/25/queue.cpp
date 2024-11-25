#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;  // Used for push operations
    stack<int> outputStack; // Used for pop and peek operations

public:
    MyQueue() {
        // Constructor: No initialization required
    }
    
    void push(int x) {
        // Push element into the input stack
        inputStack.push(x);
    }
    
    int pop() {
        // If output stack is empty, transfer elements from input stack
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        // Pop the top element from the output stack
        int val = outputStack.top();
        outputStack.pop();
        return val;
    }
    
    int peek() {
        // If output stack is empty, transfer elements from input stack
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        // Return the top element from the output stack
        return outputStack.top();
    }
    
    bool empty() {
        // Queue is empty if both stacks are empty
        return inputStack.empty() && outputStack.empty();
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