#include <stack>
using namespace std;

class MinStack {
public:
    // Constructor to initialize the stack object
    MinStack() {
        // No initialization needed as we are using the STL stack
    }

    // Method to push an element onto the stack
    void push(int val) {
        // Push the value onto the main stack
        main_stack.push(val);
        // If min_stack is empty or the new value is less than or equal to the current minimum, push it onto the min_stack
        if (min_stack.empty() || val <= min_stack.top()) {
            min_stack.push(val);
        }
    }

    // Method to remove the top element from the stack
    void pop() {
        // If the top element of main_stack is equal to the top of min_stack, pop from min_stack as well
        if (main_stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        main_stack.pop(); // Pop from main_stack
    }

    // Method to get the top element of the stack
    int top() {
        return main_stack.top(); // Return the top element of main_stack
    }

    // Method to get the minimum element in the stack
    int getMin() {
        return min_stack.top(); // Return the top element of min_stack (the current minimum)
    }

private:
    stack<int> main_stack; // Stack to store all the values
    stack<int> min_stack;  // Stack to store the minimum values
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Example usage
#include <iostream>

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl; // Output: -3
    obj->pop();
    cout << obj->top() << endl;    // Output: 0
    cout << obj->getMin() << endl; // Output: -2
    delete obj; // Clean up the allocated memory
    return 0;
}