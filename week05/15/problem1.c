#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
        
    while (head && (head->val == val)) head = head->next;

    struct ListNode *curr = head, *prev = NULL;
    while (curr) {        
        if (curr->val == val) prev->next = curr->next;            
        else prev = curr;
        curr = curr->next;
    }
    return head;
}