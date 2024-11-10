class MinStack {
public:
    // Pair to store the value and the current minimum when that value is pushed
    vector<pair<int, int>> stack;

    // Constructor
    MinStack() {
        
    }
    
    // Push the value onto the stack and update the current minimum
    void push(int val) {
        if (stack.empty()) {
            stack.push_back({val, val});
        } else {
            // Store the value along with the minimum between the current value and the previous minimum
            int currentMin = min(val, stack.back().second);
            stack.push_back({val, currentMin});
        }
    }
    
    // Pop the top element from the stack
    void pop() {
        stack.pop_back();
    }
    
    // Return the top element of the stack
    int top() {
        return stack.back().first;
    }
    
    // Return the current minimum element in the stack
    int getMin() {
        return stack.back().second;
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
