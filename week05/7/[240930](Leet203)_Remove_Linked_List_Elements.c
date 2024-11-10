//문제 : 어떤 Singlyl linked list의 head가 주어졌을 때, SLL에서 특정 val값 가지는 node를 모두 제거&& return new head

/*문제풀이1
    1. dummy_head를 생성한다. struct ListNode 생성 + dummy_head.next = head 
        dummy_head.val의 값은 0<=val<=50 이외의 값. (왜냐면 target_val의 범위가 0<=target_val<=50이므로)
    2. prev, cur을 two pointer처럼 해서 remove 작업을 진행한다. (prev: target_val 이전 노드에 고정, cur: 하나씩 움직이며 전체 node 탐색)
        remove : prev->next = cur->next 하고 cur만 update
        else : prev, cur 함께 update
    3. 반환은 dummy_head.next
*/

#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int target_val) {
    struct ListNode* dummy_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy_head->val = -1;
    dummy_head->next = head;

    struct ListNode* prev = dummy_head;
    struct ListNode* cur = head;

    while(cur != NULL){
        if (cur->val == target_val){ //prev는 고정하고 cur만 움직임. 
            prev->next = cur->next; //cur을 뛰어넘을 수 있도록 연결관계 조정
            cur = cur->next;
        }
        else { // prev, cur 함께 움직임
            prev = cur;
            cur = cur->next;
        }
    }
    return dummy_head->next;
}

