#include <stdio.h>
#include <stdlib.h>


struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode* removeElements(struct ListNode* head, int val) {
    //(0) 예외 처리 및 첫 번째 노드의 값이 val인 경우 처리
    while (head != NULL && head->val == val) {
        head = head->next;
    }

    //(1) 나머지 리스트 처리
    struct ListNode* cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->val == val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}



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

int main() {

    struct ListNode* node1 = createNode(1);
    struct ListNode* node2 = createNode(2);
    struct ListNode* node3 = createNode(3);
    struct ListNode* node4 = createNode(4);
    struct ListNode* node5 = createNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    printLL(node1);
    struct ListNode* newHead = removeElements(node1, 3);
    printLL(newHead);

    return 0;
}
