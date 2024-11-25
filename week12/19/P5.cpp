#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class MyStack {
public:
    Node* head;

    MyStack() {
        head = nullptr;
    }

    void push(int x) {
        Node* new_node = new Node(x);
        new_node->next = head;
        head = new_node;
    }
    
    int pop() {
        if (head == nullptr) return -1;
        int front = head->data;
        head = head->next;
        return front;
    }
    
    int top() {
        if (head == nullptr) return -1;
        return head->data;
    }
    
    bool empty() {
        return head == nullptr;
    }
};

int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << obj->top() << endl;
    cout << obj->pop() << endl;
    cout << obj->empty() << endl;

    return 0;
}