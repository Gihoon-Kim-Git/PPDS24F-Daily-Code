#include<stack>

using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> min;

    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if(min.empty() || min.top() >= val){
            min.push(val);
        }
    }
    
    void pop() {
        if(s.top() == min.top()){
            min.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};
