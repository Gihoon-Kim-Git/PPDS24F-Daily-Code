#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
  };


struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printLL(struct ListNode* head) {
    struct ListNode* cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("END");
}


struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* cur = head;

    while ((cur != NULL) && (cur-> next != NULL) ) {
        if (cur->val == cur->next->val) { //와..중복값이 여러개있으면 cur이 업데이트가 되면 안되는거구나..
            // printf("\nDup Detected\n");
            // printf("\nBEFORE: cur: %d, cur->next: %d", cur->val, cur->next->val);
            if (cur->next->next == NULL) {
                cur->next = NULL;
            } else {
                cur->next = cur->next->next;
            }
        } else{
        cur = cur->next;

        }
    } 
    return head;
}


int main() {

    struct ListNode* node1 = createNode(1);
    struct ListNode* node2 = createNode(2);
    struct ListNode* node3 = createNode(3);
    struct ListNode* node4 = createNode(3);
    struct ListNode* node5 = createNode(3);
    struct ListNode* node6 = createNode(3);
    struct ListNode* node7 = createNode(3);
    // struct ListNode* node8 = createNode(6);
    // struct ListNode* node9 = createNode(7);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    // node7->next = node8;
    // node8->next = node9;

    printLL(node1);
    struct ListNode* newHead = deleteDuplicates(node1);
    printLL(newHead);

    return 0;
}
