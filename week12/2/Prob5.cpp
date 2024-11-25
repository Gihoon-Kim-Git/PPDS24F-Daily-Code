#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q1, q2; // 두 개의 큐를 사용하여 스택을 구현

public:
    MyStack(){
        // 생성자
    }
    
    void push(int x){
        // q2에 새로운 요소를 추가
        q2.push(x);
        
        // q1의 모든 요소를 q2로 이동
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        // q1과 q2를 swap
        swap(q1, q2);
    }
    
    int pop(){
        // q1의 front가 스택의 top이므로 pop
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
    
    int top(){
        // q1의 front가 스택의 top
        return q1.front();
    }
    
    bool empty(){
        // q1이 비어 있으면 스택이 비어 있는 것으로 간주(q1이 모든 데이터를 보유)
        return q1.empty();
    }
};