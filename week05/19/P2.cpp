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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode *temp = head->next;
        ListNode *prev = head;

        while (temp != nullptr) {
            if (temp->val == prev->val) {
                prev->next = temp->next;
            } else {
                prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};

int main() {
    ListNode *head = nullptr;
    head = insert_head(head, 3);
    head = insert_head(head, 3);
    head = insert_head(head, 2);
    head = insert_head(head, 1);
    head = insert_head(head, 1);
    printList(head);  // 1 -> 1 -> 2 -> 3 -> 3 -> nullptr
    
    Solution result;
    head = result.deleteDuplicates(head);
    printList(head);  // 1 -> 2 -> 3 -> nullptr

    return 0;
}