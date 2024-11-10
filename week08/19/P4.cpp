#include <iostream>
using namespace std;

struct ListNode {
    int val;
    int min;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode(int x, int y, ListNode *next) : val(x), min(y), next(next) {}
};

class MinStack {
public:
    ListNode *head;

    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if (head == nullptr) head = new ListNode(val, val, nullptr);
        else head = new ListNode(val, min(val, head->min), head);
    }
    
    void pop() {
        if (head != nullptr) head = head->next;       
    }
    
    int top() {
        if (head != nullptr) return head->val;
        return INT_MIN;
    }
    
    int getMin() {
        if (head != nullptr) return head->min;
        return INT_MIN;
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int param_1 = obj->getMin();
    obj->pop();
    int param_2 = obj->top();
    int param_3 = obj->getMin();
    cout << param_1 << endl;
    cout << param_2 << endl;
    cout << param_3 << endl;

    return 0;
}