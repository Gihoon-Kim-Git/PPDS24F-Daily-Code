#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> stack1, stack2;
    MyQueue() {        
    }
    
    void push(int x) {
        if (!stack1.empty()){
            while (!stack1.empty()) {
                int dat = stack1.top();   
                stack1.pop();             
                stack2.push(dat);
            }
            stack1.push(x);
            while (!stack2.empty()) {
                int dat = stack2.top();
                stack2.pop();
                stack1.push(dat);
            }        
        }
        else stack1.push(x);
    }
    
    int pop() {
        int dat = stack1.top();
        stack1.pop();
        return dat;
    }
    
    int peek() {
        return stack1.top();
    }
    
    bool empty() {
        return stack1.empty();
        
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