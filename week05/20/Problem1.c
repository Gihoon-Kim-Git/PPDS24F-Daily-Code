#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    if(!head) return NULL;

    struct ListNode* new_ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* prev = new_ptr;
    struct ListNode* temp = head;
    
    while(temp){
        if(temp->val != val){
            prev -> next = temp;
            prev = prev -> next;
        }else{
            prev->next = NULL;
        }
        temp = temp->next;
    }

    return new_ptr->next;
}