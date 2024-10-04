#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

typedef struct listType SLList;
// SLList에는 첫 노드랑 사이즈 저장
struct listType {
    struct ListNode *first;
};

struct ListNode *createNode(int x) {
    struct ListNode *newNode; //이게 주소가 되는 거임
    newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode -> val = x;
    newNode -> next = NULL;
    return newNode;
}

void addFirst(SLList *LL, int x) {
    struct ListNode *newFirst = createNode(x);
    //새로 만든 노드를 처음으로 만들고, 기존에 첫 번째를 다음으로 만듦
    newFirst -> next = LL -> first;
    LL -> first = newFirst;
}

void printSLList(SLList *LL){
    struct ListNode *curr = LL ->first;
    printf("allVals: ");
    while (curr!= NULL){
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("END\n");
}

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main(void) {
    SLList myLL = {NULL};
    printSLList(&myLL);

    addFirst(&myLL, 10);
    printSLList(&myLL);
    
    addFirst(&myLL, 20);
    printSLList(&myLL);

    addFirst(&myLL, 345890);
    printSLList(&myLL);
    
    addFirst(&myLL, 30);
    printSLList(&myLL);

    addFirst(&myLL, 10);
    printSLList(&myLL);

    struct ListNode *mid = middleNode(myLL.first);
    printf("%d\n", mid->val);

    return 0;
}