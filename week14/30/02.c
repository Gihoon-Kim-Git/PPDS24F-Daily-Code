#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
};

//________SUPPORT______//
struct ListNode* createNode(int val) {
    struct ListNode* myNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    myNode->val = val;
    myNode->next = NULL;

    return myNode;
}

void appendNode(struct ListNode* root, int val) {
    struct ListNode* cur = root;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = createNode(val);
}

void printLL(struct ListNode* root) {
    struct ListNode* cur = root;
    while (cur->next != NULL) {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("%d -> END\n", cur->val);
}

void freeLL(struct ListNode* root) {
    struct ListNode* cur = root;
    while (cur->next != NULL) {
        struct ListNode* nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    free(cur);
}

//________MAIN__________//
struct ListNode* swapPairs(struct ListNode* head) {

//예외 case
    if (head == NULL) {return NULL;}
    if (head->next == NULL) {return head;}

//보통 case (두번째까지 null이 아닌 경우)
    struct ListNode* node1 = head;
    struct ListNode* node2 = head->next;
    struct ListNode* newHead = head->next;

    while ((node2 != NULL)) {//(null->next)가 정의 불가.
        //예외
        if (node2->next == NULL) {
            node2->next = node1;
            node1->next = NULL;
            break;
        } else {
        //(1). 재연결하기
            struct ListNode* node4 = node2->next->next;   
            struct ListNode* node3 = node2->next;
            if (node4 == NULL) {
                node2->next = node1;
                node1->next = node3;
                break;
            } else {
                node2->next = node1;
                node1->next = node4;
                // printf("Node1 %d; Node2 %d; Node3: %d\n", node1->val, node2->val, temp->val);
                //(2). 다음을 위한 update
                    node1 = node3;
                    node2 = node4;
            }
        }

    }
    //(3). node2 or node3 둘중에 하나라도 NULL이게 된 상황
    printf("WHILE OUT!!");
    printLL(newHead);
    return newHead;
}



int main() {
    struct ListNode* Root1 = createNode(1);
    appendNode(Root1, 2); appendNode(Root1, 3); //appendNode(Root1, 4);
    printf("ORIGINAL: "); printLL(Root1);
    struct ListNode* Root1Swapped = swapPairs(Root1); 


    // printf("SWAPPED_: "); printLL(Root1Swapped);

    freeLL(Root1Swapped);
    return 0;
}