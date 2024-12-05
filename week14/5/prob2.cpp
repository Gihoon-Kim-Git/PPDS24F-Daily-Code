// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // base case
        if (head == nullptr) {
            return nullptr;
        }
        else if (head->next == nullptr) {
            return head;
        }

        // recursive case
        ListNode* nextnext = head->next->next;
        ListNode* next = head->next;
        next->next = head;
        head->next = swapPairs(nextnext);
        return next;
    }
};
