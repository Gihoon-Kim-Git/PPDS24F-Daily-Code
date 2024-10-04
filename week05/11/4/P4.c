#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

typedef struct ListNode ListNode;
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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* cur = head;

    while(list1 && list2){
        if(list1->val > list2->val){
            cur->next = list2;
            list2 = list2->next;
        }
        else{
            cur->next = list1;
            list1 = list1->next;
        }
        cur = cur->next;
    }
    if(list1){
        cur->next = list1;
    }
    if(list2){
        cur->next = list2;
    }
    ListNode* result = head->next;
    free(head);
    return result;
}

int main(void) {
    SLList myLL = {NULL};
    SLList myLL1 = {NULL};

    addFirst(&myLL, 4);
    
    addFirst(&myLL, 2);

    addFirst(&myLL, 1);
    
    addFirst(&myLL1, 7);

    addFirst(&myLL1, 6);

    addFirst(&myLL1, 3);

    printSLList(&myLL);

    struct ListNode *merge = mergeTwoLists(myLL.first, myLL1.first);
    SLList result = {merge};
    printSLList(&result);

    return 0;
}