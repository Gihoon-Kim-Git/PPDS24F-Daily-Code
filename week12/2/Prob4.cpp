#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stack1, stack2;

public:
    MyQueue(){
        // 기본 생성자
    }
    
    void push(int x){
        // push 시 stack1에 데이터를 추가
        stack1.push(x);
    }
    
    int pop(){
        // stack2가 비어 있는 경우에만 stack1의 모든 데이터를 stack2로 옮김
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // stack2의 맨 위의 요소를 제거하고 반환
        int topElement = stack2.top();
        stack2.pop();
        return topElement;
    }
    
    int peek(){
        // pop과 마찬가지로 stack2가 비어 있는 경우 stack1의 모든 데이터를 stack2로 옮김
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // stack2의 맨 위의 요소를 반환
        return stack2.top();
    }
    
    bool empty(){
        // 두 스택이 모두 비어 있으면 큐가 비어 있는 것으로 간주
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
