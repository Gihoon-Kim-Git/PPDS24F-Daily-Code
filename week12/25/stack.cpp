#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1; // Main queue to hold the elements
    queue<int> q2; // Auxiliary queue for swapping

public:
    MyStack() {
        // Constructor
    }
    
    void push(int x) {
        // Push the element into q2
        q2.push(x);
        // Transfer all elements from q1 to q2 to maintain stack order
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Swap q1 and q2 to keep q1 as the main queue
        swap(q1, q2);
    }
    
    int pop() {
        // Pop the top element from q1
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        // Return the front element of q1 (which is the top of the stack)
        return q1.front();
    }
    
    bool empty() {
        // Check if q1 is empty
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */