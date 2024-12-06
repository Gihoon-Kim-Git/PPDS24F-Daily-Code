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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *curr = head;
        ListNode *next = curr->next;
        int odd = 0;
        while (next != nullptr) {
            if (odd%2 == 0) {
                int temp = next->val;
                next->val = curr->val;
                curr->val = temp;
            }
            odd++;
            curr = curr->next;
            next = next->next;
        }
        return head;
    }
};

int main() {
    ListNode *head = nullptr;
    head = insert_head(head, 4);
    head = insert_head(head, 3);
    head = insert_head(head, 2);
    head = insert_head(head, 1);
    printList(head);
    Solution result;
    ListNode *new_head = result.swapPairs(head);
    printList(new_head);

    return 0;
}