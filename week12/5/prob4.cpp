#include <vector>
// #include <iostream>
using namespace std;

class MyQueue {
public:
    vector<int> stack_push;
    vector<int> stack_pop;

    MyQueue() {
    }
    
    void push(int x) {
        // cout << "Before push (" << x << ")" << endl;
        // cout << "push size : " << stack_push.size() << endl;
        // cout << " pop size : " << stack_pop.size() << endl << endl;

        // stack_pop 에 원소가 있다면 : stack_push 로 옮기기
        while (!stack_pop.empty()) {
            stack_push.push_back(stack_pop.back());
            stack_pop.pop_back();
        }
        // stack_push 에 원소 추가
        stack_push.push_back(x);

        // cout << "After push (" << x << ")" << endl;
        // cout << "push size : " << stack_push.size() << endl;
        // cout << " pop size : " << stack_pop.size() << endl << endl;
    }
    
    int pop() {
        // cout << "Before pop" << endl;
        // cout << "push size : " << stack_push.size() << endl;
        // cout << " pop size : " << stack_pop.size() << endl << endl;

        // stack_push 에 원소가 있다면 : stack_pop 으로 옮기기
        while (!stack_push.empty()) {
            // cout << "??? push -> pop" << endl;
            stack_pop.push_back(stack_push.back());
            stack_push.pop_back();
        }
        // stack_pop 의 마지막 원소 삭제 및 반환
        int pop_element = stack_pop.back();
        stack_pop.pop_back();

        // cout << "After pop" << endl;
        // cout << "push size : " << stack_push.size() << endl;
        // cout << " pop size : " << stack_pop.size() << endl << endl;
        return pop_element;
    }
    
    int peek() {
        // cout << "Before peek" << endl;
        // cout << "push size : " << stack_push.size() << endl;
        // cout << " pop size : " << stack_pop.size() << endl << endl;

        // stack_push 에 원소가 있다면 : stack_pop 으로 옮기기
        while (!stack_push.empty()) {
            // cout << "??? push -> pop" << endl;
            stack_pop.push_back(stack_push.back());
            stack_push.pop_back();
        }
        // stack_pop 의 마지막 원소 반환
        int pop_element = stack_pop.back();
        
        // cout << "After peek" << endl;
        // cout << "push size : " << stack_push.size() << endl;
        // cout << " pop size : " << stack_pop.size() << endl << endl;
        return pop_element;
    }
    
    bool empty() {
        if (stack_push.empty() && stack_pop.empty()) return true;
        else return false;
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
