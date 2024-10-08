#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insert_head(ListNode *head, int val) {
    ListNode *new_node = new ListNode(val, head);
    return new_node;
};

void printList(ListNode* head) {
    ListNode* current_node = head;
    while (current_node != nullptr) {
        cout << current_node->val << " -> ";
        current_node = current_node->next;
    }
    cout << "nullptr" << endl;
}

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

int main() {
    ListNode *head = nullptr;
    head = insert_head(head, 6);
    head = insert_head(head, 5);
    head = insert_head(head, 4);
    head = insert_head(head, 3);
    head = insert_head(head, 2);
    head = insert_head(head, 1);
    printList(head);  // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> nullptr
    
    Solution result;
    head = result.middleNode(head);
    printList(head);  // 4 -> 5 -> 6 -> nullptr

    return 0;
}