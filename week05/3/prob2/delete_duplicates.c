#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    // empty or one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // initialization: traversal pointer
    struct ListNode* curr = head;

    // traversal
    while (curr != NULL && curr->next != NULL) {
        if (curr->val == curr->next->val) {
            // bypass next node
            struct ListNode* temp = curr->next; // temporary node to hold the duplicate
            curr->next = curr->next->next; // bypass duplicate node
            free(temp); // free memory of duplicate node
        } else {
            // move pointer to next node
            curr = curr->next;
        }
    }

    return head;
}