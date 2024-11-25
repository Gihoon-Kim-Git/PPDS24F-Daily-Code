#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> stack1;  // Used for push operations
    stack<int> stack2;  // Used for pop/peek operations

    void move() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        move();
        int top = stack2.top();
        stack2.pop();
        return top;
    }

    int peek() {
        move();
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

// Example usage
int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    cout << queue.peek() << endl;  // Output: 1
    cout << queue.pop() << endl;   // Output: 1
    cout << queue.empty() << endl; // Output: 0
    return 0;
}
