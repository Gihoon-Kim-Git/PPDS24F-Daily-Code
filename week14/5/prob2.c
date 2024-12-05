#include <stdio.h>      // NULL : 0 으로 정의된 매크로


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    // base case
    if (head == NULL) {
        return NULL;
    }
    else if (head->next == NULL) {
        return head;
    }

    // recursive case
    struct ListNode* nextnext = head->next->next;
    struct ListNode* next = head->next;

    next->next = head;
    head->next = swapPairs(nextnext);
    return next;
};
