class MyQueue {
private:
    std::stack<int> inStack;  // 삽입을 담당하는 스택
    std::stack<int> outStack; // 제거를 담당하는 스택

    // inStack의 데이터를 outStack으로 옮기는 함수
    void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    // 큐에 요소를 삽입
    void push(int x) {
        inStack.push(x);
    }

    // 큐에서 요소를 제거하고 반환
    int pop() {
        if (outStack.empty()) {
            if (inStack.empty()) {
                throw std::runtime_error("Queue is empty");
            }
            transfer();
        }
        int ans = outStack.top();
        outStack.pop();
        return ans;
    }

    // 큐의 첫 번째 요소를 반환 (제거하지 않음)
    int peek() {
        if (outStack.empty()) {
            if (inStack.empty()) {
                throw std::runtime_error("Queue is empty");
            }
            transfer();
        }
        return outStack.top();
    }

    // 큐가 비었는지 확인
    bool empty() {
        return inStack.empty() && outStack.empty();
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