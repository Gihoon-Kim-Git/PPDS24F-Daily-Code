//문제에 앞서 queue의 method 정리
    // 선언 : queue<int> q;
    // q.push();
    // q.pop(); 파이썬과 달리 값을 반환하지 않음.
    // q.empty();
    // q.front();


// 1. Using 2 queues

#include <queue>
#include <vector>
using namespace std;

class MyStack {
public:
    queue<int> store_q; //멤버변수로 선언
    queue<int> temp_q;//멤버변수로 선언

    MyStack() {
    }
    
    void push(int x) {
        store_q.push(x);
    }

    int pop() {
        int n = store_q.size();
        for (int i = 0; i < n-1; i++){
            int t = store_q.front();
            store_q.pop();
            temp_q.push(t);
        }

        int popped_element = store_q.front();
        store_q.pop();

        swap(store_q, temp_q);

        return popped_element;
    }
    
    int top() {
        int n = store_q.size();
        for (int i = 0; i < n-1; i++){
            int t = store_q.front();
            store_q.pop();
            temp_q.push(t);
        }

        int top_element = store_q.front();
        store_q.pop();
        temp_q.push(top_element);

        swap(store_q, temp_q);

        return top_element;
    }
    
    bool empty() {
        return store_q.empty();
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




// 2. Using 1 queue------------------------------------------------------------------

#include <queue>
#include <vector>
using namespace std;


class MyStack {
    queue<int> q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size()-1; i++){
            int t = q.front();
            q.pop();
            q.push(t);
        }
    }
    
    int pop() {
        int popped_element = q.front();
        q.pop();
        return popped_element;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};