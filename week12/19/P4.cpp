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

class MyQueue {
public:
    Node* head;

    MyQueue() {
        head = nullptr;
    }

    void push(int x) {
        Node* new_node = new Node(x);
        if (head == nullptr) head = new_node; return;
        Node* last_node = head;
        while (last_node->next != nullptr) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
    
    int pop() {
        if (head == nullptr) return -1;
        int front = head->data;
        head = head->next;
        return front;
    }
    
    int peek() {
        if (head == nullptr) return -1;
        return head->data;
    }
    
    bool empty() {
        return head == nullptr;
    }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    cout << obj->peek() << endl;
    cout << obj->pop() << endl;
    cout << obj->empty() << endl;

    return 0;
}