#include <stack>

using namespace std;

class MyQueue {
public:

    stack<int> stack1, stack2;
    
    void transfer() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    MyQueue() {}
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        if (stack2.empty()) transfer();
        int top = stack2.top();
        stack2.pop();
        return top;
    }
    
    int peek() {
        if (stack2.empty()) transfer();
        return stack2.top();
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
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