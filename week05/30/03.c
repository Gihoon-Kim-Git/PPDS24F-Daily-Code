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
    printf("END\n");
}


struct ListNode* middleNode(struct ListNode* head) {
//0. 예외
//1. last index를 구한다. head = idx 0
    struct ListNode* cur = head;
    int i = 0;   
    while (cur->next != NULL) {
        cur = cur->next;
        i++;
    }
    printf("last: %d", i);

//2. mid index를 구한다.
    int mid_idx;
    if (i % 2 == 1) {
        mid_idx = i/2 +1;
    } else {
        mid_idx = i/2;
    }
    printf("mid: %d\n ", mid_idx);

//3. 그걸 head로해서 return한다.
    struct ListNode* cur2 = head;
    int j = 0;
    while (j < mid_idx) {
        cur2 = cur2->next;
        j++;
    }

    return cur2;
}


int main() {

    struct ListNode* node1 = createNode(1);
    struct ListNode* node2 = createNode(2);
    struct ListNode* node3 = createNode(3);
    struct ListNode* node4 = createNode(4);
    struct ListNode* node5 = createNode(5);
    struct ListNode* node6 = createNode(6);
    // struct ListNode* node7 = createNode(7);
    // struct ListNode* node8 = createNode(6);
    // struct ListNode* node9 = createNode(7);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    // node6->next = node7;
    // node7->next = node8;
    // node8->next = node9;

    printLL(node1);
    struct ListNode* newHead = middleNode(node1);
    printLL(newHead);

    return 0;
}
