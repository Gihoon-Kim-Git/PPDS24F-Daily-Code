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
        // If the list is empty or has only one node, just return it as is.
        if (!head || !head->next) return head;

        // Dummy node that points to the start of the list
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy; 
        ListNode* curr = head;

        while (curr && curr->next) {
            // Identify the two nodes to swap
            ListNode* first = curr;
            ListNode* second = curr->next;

            // Swap the pair
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move prev two nodes ahead
            prev = first;
            // Move curr to the next pair
            curr = first->next;
        }

        return dummy.next;
    }
};