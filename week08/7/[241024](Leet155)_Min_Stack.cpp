
#include <iostream>
#include <vector>
using namespace std;

#define MAX_INT 2147483647 // #define MAX_INT ((1LL << 31) - 1)  <--   2**31-1과 같음. 여기서 1LL이라고 쓰는 이유는 1<<31하면 int타입이 아니라 Longlong이기 때문.

class MinStack {
    vector<int> stack;
    int min_element = MAX_INT;

public:
    MinStack() {
        stack = {};
    }
    
    void push(int val) {
        stack.push_back(val);
        if (val < min_element) min_element = val;
    }
    
    void pop() {
        int del_el = stack.back();
        stack.pop_back();
        if (del_el == min_element){
            min_element = MAX_INT;
            for (auto a : stack){
                if (a < min_element) min_element = a;
            }
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min_element;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */