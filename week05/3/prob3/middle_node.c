#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head) {
    
    // initialization: two pointers
    struct ListNode* slow = head; // 1 step
    struct ListNode* fast = head; // 2 steps

    // traversal
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // slow pointer moves 1 step
        fast = fast->next->next;  // fast pointer moves 2 steps
    }

    return slow; // slow pointer will now point to the middle node
}
