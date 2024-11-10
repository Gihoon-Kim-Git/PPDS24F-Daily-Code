#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyCircularDeque {
public:
    ListNode *head;
    int size = 0;
    int capa;

    MyCircularDeque(int k) {
        head = nullptr;
        capa = k;
    }
    
    bool insertFront(int value) {
        if (size >= capa) return false;
        ListNode* new_node = new ListNode(value);
        size++;
        if (head == nullptr) {
            head = new_node;
            return true;
        }
        new_node->next = head;
        head = new_node;
        return true;
    }
    
    bool insertLast(int value) {
        if (size >= capa) return false;
        ListNode* new_node = new ListNode(value);
        size++;
        if (head == nullptr) {
            head = new_node;
            return true;
        }
        ListNode* last_node = head;
        while (last_node->next != nullptr) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
        return true;
    }
    
    bool deleteFront() {
        if (head == nullptr) return false;
        head = head->next;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (head == nullptr) return false;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            ListNode* cur_node = head;
            ListNode* prev_node = nullptr;
            while (cur_node->next != nullptr) {
                prev_node = cur_node;
                cur_node = cur_node->next;
            }
            delete cur_node;
            prev_node->next = nullptr;
        }
        size--;
        return true;
    }
    
    int getFront() {
        if (head != nullptr) return head->val;
        return -1;
    }
    
    int getRear() {
        if (head == nullptr) return -1;
        ListNode* cur_node = head;
        while (cur_node->next != nullptr) {
            cur_node = cur_node->next;
        }
        return cur_node->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capa;
    }
};

int main() {
    MyCircularDeque* obj = new MyCircularDeque(4);
    bool param_1 = obj->insertFront(9);
    bool param_2 = obj->deleteLast();
    int param_3 = obj->getRear();
    int param_4 = obj->getFront();
    int param_5 = obj->getFront();
    bool param_6 = obj->deleteFront();
    bool param_7 = obj->insertFront(6);
    bool param_8 = obj->insertLast(5);
    bool param_9 = obj->insertFront(9);
    int param_10 = obj->getFront();
    bool param_11 = obj->insertFront(6);
    cout << param_1 << endl;
    cout << param_2 << endl;
    cout << param_3 << endl;
    cout << param_4 << endl;
    cout << param_5 << endl;
    cout << param_6 << endl;
    cout << param_7 << endl;
    cout << param_8 << endl;
    cout << param_9 << endl;
    cout << param_10 << endl;
    cout << param_11 << endl;

    return 0;
}