#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> stackData;  // 일반 스택
    stack<int> minStack;   // 최소값 스택

public:
    MinStack() {

    }
    
    void push(int val) {
        stackData.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (stackData.top() == minStack.top()) {
            minStack.pop();
        }
        stackData.pop();
    }
    
    int top() {
        return stackData.top(); 
    }
    
    int getMin() {
        return minStack.top();
    }
};