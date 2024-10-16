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

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head){
        return head;
    }
    struct ListNode* curr = head;
    struct ListNode* fir = head;
    int temp = head->val;
    while(curr){
        if(curr->val == temp){
            curr = curr->next;
            fir->next = curr;
        }
        else{
            temp = curr->val;
            fir = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main(void) {
    //Struct 초기화할때 각 instance를 {}에 넣어서 만들 수 있음
    SLList myLL = {NULL};
    printSLList(&myLL);

    addFirst(&myLL, 20);
    printSLList(&myLL);
    
    addFirst(&myLL, 20);
    printSLList(&myLL);

    addFirst(&myLL, 10);
    printSLList(&myLL);
    
    addFirst(&myLL, 10);
    printSLList(&myLL);

    addFirst(&myLL, 10);
    printSLList(&myLL);

    myLL.first = deleteDuplicates(myLL.first);
    printSLList(&myLL);

    return 0;
}