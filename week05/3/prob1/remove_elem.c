#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* removeElements(struct ListNode* head, int val) {
    // initialization: dummy node
    // dummy: helps in cases where the head node itself needs to be removed
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0; // value of dummy node doesn't matter
    dummy->next = head; // dummy node points to the head of the list

    // initialization: two pointers
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;

    // traverse linked list
    while (curr != NULL) {
        if (curr->val == val) {
            // skip curr node
            prev->next = curr->next;
        } else {
            // move prev node to curr
            prev = curr;
        }
        // move curr node to next
        curr = curr->next;
    }

    // store new head and free dummy node
    struct ListNode* newHead = dummy->next;
    free(dummy);

    // return new head
    return newHead;
}