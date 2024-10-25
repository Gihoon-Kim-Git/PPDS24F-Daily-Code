#include <vector>
using namespace std;

class MinStack {
private:
    vector<int> minHistory;
    vector<int> vals;

public:
    MinStack() {
    }
    
    void push(int val) {
        vals.push_back(val);
        // 1st push
        if (minHistory.size() == 0) minHistory.push_back(val);
        // val 이 minimum 의 자격을 갖추었다면
        else if (val <= minHistory.back()) minHistory.push_back(val);
    }
    
    void pop() {
        // 현재 minimum 을 pop 하는 경우 : 현재의 minimum 은 push 당시 minimum 의 자격을 갖춘 자임.
        if (vals.back() == minHistory.back()) minHistory.pop_back();
        vals.pop_back();
    }
    
    int top() {
        return vals.back();
    }
    
    int getMin() {
        return minHistory.back();
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
