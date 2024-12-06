class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node to simplify edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap the pair
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev to the next pair
            prev = first;
        }

        return dummy.next;
    }
};
