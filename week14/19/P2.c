#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addElements(struct ListNode *head, int val) {
    struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = head;
    return new_node;
}


void printList(struct ListNode *head) {
    struct ListNode *current_node = head;
    while (current_node != NULL) {
        printf("%d -> ", current_node->val);
        current_node = current_node->next;
    }
    printf("nullptr\n");
}

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *curr = head;
    struct ListNode *next = curr->next;
    int odd = 0;
    while (next != NULL) {
        if (odd%2 == 0) {
            int temp = next->val;
            next->val = curr->val;
            curr->val = temp;
        }
        odd++;
        curr = curr->next;
        next = next->next;
    }
    return head;
}

int main() {
    struct ListNode *head = NULL;
    head = addElements(head, 4);
    head = addElements(head, 3);
    head = addElements(head, 2);
    head = addElements(head, 1);
    printList(head);

    struct ListNode *new_head = swapPairs(head);
    printList(new_head);
    
    return 0;
}