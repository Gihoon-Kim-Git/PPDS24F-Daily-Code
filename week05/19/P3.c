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

struct ListNode* middleNode1(struct ListNode* head) {
    int count = 0;
    struct ListNode *temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    for (int i=0; i<count/2; i++) {
        head = head->next;
    }

    return head;
}

struct ListNode* middleNode2(struct ListNode* head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
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
    struct ListNode *head1 = NULL;
    struct ListNode *head2 = NULL;
    head = addElements(head, 6);
    head = addElements(head, 5);
    head = addElements(head, 4);
    head = addElements(head, 3);
    head = addElements(head, 2);
    head = addElements(head, 1);
    printList(head);  // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> nullptr

    head1 = middleNode1(head);
    printList(head1);  // 4 -> 5 -> 6 -> nullptr
    
    head2 = middleNode1(head);
    printList(head2);  // 4 -> 5 -> 6 -> nullptr

    return 0;
}