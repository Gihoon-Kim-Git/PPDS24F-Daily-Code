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

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return head;
    
    struct ListNode *temp = head->next;
    struct ListNode *prev = head;

    while (temp != NULL) {
        if (temp->val == prev->val) {
            prev->next = temp->next;
        } else {
            prev = temp;
        }
        temp = temp->next;
    }
    return head;
}

void printList(struct ListNode *head) {
    struct ListNode *current_node = head;
    while (current_node != NULL) {
        printf("%d -> ", current_node->val);
        current_node = current_node->next;
    }
    printf("nullptr\n");
}

int main() {
    struct ListNode *head = NULL;
    head = addElements(head, 3);
    head = addElements(head, 3);
    head = addElements(head, 2);
    head = addElements(head, 1);
    head = addElements(head, 1);
    printList(head);  // 1 -> 1 -> 2 -> 3 -> 3 -> nullptr

    head = deleteDuplicates(head);
    printList(head);  // 1 -> 2 -> 3 -> nullptr
    
    return 0;
}