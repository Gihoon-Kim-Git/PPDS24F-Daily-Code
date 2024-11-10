#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // dummy node
    // helps avoid dealing with edge cases like initializing new list's head
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    
    struct ListNode* curr = dummy;

    // traverse both lists
    while (list1 != NULL && list2 != NULL) {
        // add nodes
        if (list1->val <= list2->val) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
        // move curr pointer
        curr = curr->next;
    }

    // append nodes in remaining list
    if (list1 != NULL) {
        curr->next = list1;
    } else if (list2 != NULL) {
        curr->next = list2;
    }

    struct ListNode* mergedList = dummy->next;
    free(dummy); // free the dummy node
    return mergedList;
}
