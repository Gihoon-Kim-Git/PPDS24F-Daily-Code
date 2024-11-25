#include <queue>
using namespace std;

class MyStack {
private:
    // queue1 혹은 queue2 둘 중 어느 한 곳에만 data 존재
    queue<int> queue1;
    // queue<int> queue2;
public:
    MyStack() {}
    
    void push(int x) {
        queue1.push(x);
    }
    
    int pop() {
        // queue 한 바퀴 돌리면서 마지막 element 탐색
        queue1.push(-1);
        int temp;
        while(true) {
            // 하나 빼놓기
            temp = queue1.front();
            queue1.pop();
            // 방금 빼놓은게 한 바퀴 다 돌고 마지막 원소였으면 
            // - 구분자 -1 제거 후 while 문 종료 (temp 는 버림)
            if (queue1.front() == -1) {
                queue1.pop();
                break;
            }
            // 아직 한 바퀴 다 안 돌았으면
            // - 빼놓은 temp 다시 집어넣기
            else {
                queue1.push(temp);
            }
        }
        return temp;
    }
    
    int top() {
        // queue 한 바퀴 돌리면서 마지막 element 탐색
        queue1.push(-1);
        int temp;
        while(true) {
            // 하나 빼놓기
            temp = queue1.front();
            queue1.pop();
            // 방금 빼놓은게 한 바퀴 다 돌고 마지막 원소였으면 
            // - 구분자 -1 제거 후 while 문 종료 (temp 유지; 다시 집어넣기)
            if (queue1.front() == -1) {
                queue1.pop();
                queue1.push(temp);
                break;
            }
            // 아직 한 바퀴 다 안 돌았으면
            // - 빼놓은 temp 그냥 다시 집어넣기
            else {
                queue1.push(temp);
            }
        }
        return temp;
    }
    
    bool empty() {
        return queue1.empty();
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
