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

// struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
// //0. 예외
//     if (list1 == NULL) {
//         return list2;
//     } else if (list2 == NULL) {
//         return list1;
//     }
// //1. 기준 만들고 cur1 cur2
//     struct ListNode* cur1 = list1;   
//     struct ListNode* cur2 = list2;     
// //2.1 cur1을 기준으로 cur1 < cur2 <= cur1->next 이면 끼워넣기
//     while ((cur1->next != NULL) && (cur2->next != NULL) ) {
//             struct ListNode* temp2 = cur2->next;
//             struct ListNode* temp1 = cur1->next;
//         if ((cur1->val < cur2->val) && (cur2->val <= cur1->next->val)) {
//             // printf("insert: cur1: %d, cur2: %d, cur1->next: %d\n", cur1->val, cur2->val, cur1->next->val);
//             cur1->next = cur2;
//             cur2->next = temp1;
//             cur1 = cur1->next; //cur1은 cur2가 되고
//             cur2 = temp2; //cur2는 전진
//         } else if (cur1->val >= cur2->val) { // cur2->val, cur1->val
//                 // printf("insert: cur2: %d, cur1: %d\n", cur2->val, cur1->val);
//                 cur2->next = cur1;
//                 //업데이트
//                 cur1 = cur2;
//                 cur2 = temp2;
//                 list1 = cur1;
//                 printf("CUR1: %d, CUR2: %d", cur1->val, cur2->val);
//         } else { //끼워넣을 필요없으면 cur1만 전진      cur2  > cur1->next
//             // printf("cur1: %d, cur1->next: %d, cur2: %d\n", cur1->val, cur1->next->val, cur2->val);
//             cur1 = cur1->next;
//         } 
//     }
// //2.2. 둘중 하나가 끝났으면 나머지 붙여넣기.
//     if (cur1->next == NULL) { //1만 끝났으면
//         cur1->next = cur2;
//         printf("cur1 ends");
//     } else if (cur2->next == NULL) { //2만 끝났으면
//         struct ListNode* temp1 = cur1->next;
//         cur1->next = cur2;
//         cur2->next = temp1;
//         printf("cur2 ends");
//     }
//     printf("cur1 %d, cur2 %d", cur1->val, cur2->val);
// //3. list1 return하기
//     return list1;
// }

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* newHead = createNode(-99);
    struct ListNode* cur1 = list1;
    struct ListNode* cur2 = list2;      
    struct ListNode* cur0 = newHead;

    while ((cur1 != NULL) && (cur2 != NULL)) {    
        //case1:   cur2 >= cur1
        if (cur2->val >= cur1->val) {
            cur0->next = cur1;
            cur1 = cur1->next;
        } 
        //case2:   cur2 < cur1
        else {
            cur0-> next = cur2;
            cur2 = cur2->next;
        }
        cur0 = cur0->next;

    }

//3. 남은거 붙여주기
    //3.1 둘다 곧 끝날때
    if ((cur1 == NULL) && (cur2 == NULL)) {
    } else if (cur1 == NULL) { //3.2  cur1 만 끝났을때
        cur0->next = cur2;
    } else if (cur2 == NULL) { //3.3 cur2  만 끝났을때. 
        cur0->next = cur1;
    } 
    return newHead->next;
}
int main() {

    struct ListNode* node1 = createNode(2);
    struct ListNode* node2 = createNode(4);
    // struct ListNode* node3 = createNode(4);
    // struct ListNode* node4 = createNode(10);
    // struct ListNode* node5 = createNode(11);
    // struct ListNode* node6 = createNode(15);
    node1->next = node2;
    // node2->next = node3;
    // node3->next = node4;
    // node4->next = node5;
    // node5->next = node6;

    struct ListNode* nodeA = createNode(0);
    // struct ListNode* nodeB = createNode(3);
    // struct ListNode* nodeC = createNode(4);
    // nodeA->next = nodeB;
    // nodeB->next = nodeC;

    printLL(node1);
    printLL(nodeA);

    struct ListNode* newHead = mergeTwoLists(node1, nodeA);
    printLL(newHead);

    return 0;
}
