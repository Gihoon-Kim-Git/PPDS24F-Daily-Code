/*문제
2개의 sorted SLL이 있을 때, 이것들을 하나의 sorted SLL로 변환.(non-decreasing order)
return the head of the merged linked list.*/

/*문제풀이1 : recursive 
    1. 둘 중에 하나가 None이면 다른 SLL head를 return
    2. None이 아니라면, val을 비교해서, 
        list1.val <= list2.val : list1.next = merge(list1.next, l2) return list1
        list1.val > list2.val : list2.next = merge(list2.next, l1) return list2
*/

/*문제풀이2 : 
    1. dummy_head를 새로운 head로 만들어주고 여기서 new_cur을 돌리면서 list1, list2의 요소를 비교하면서 그 중에 작은 거를 new_cur의 next로 지정해주는 방식.
    2. temp1, temp2를 동시에 움직이면서 하나하나 덧붙여주다가, 하나가 먼저 NULL에 도달할 경우, 도달못한 다른 temp를 next로 덧붙이면 됨.
    3. return은 dummy_head->next.
*/

#include <stdio.h>
#include <stdlib.h>

// * Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

//풀이 1
struct ListNode* mergeTwoList(struct ListNode* list1, struct ListNode* list2){
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    if (list1->val <= list2->val) {
        list1->next = mergeTwoList(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoList(list2->next, list1);
        return list2;
    }
}

//풀이 1-1(풀이1이랑 같은 풀이인데, merged_cur이 있어서 보다 이해가 쉬움)
struct ListNode* mergeTwoList(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL) return list2;
    if(list2 == NULL)return list1;

    struct ListNode* merged_cur = (struct ListNode*)malloc(sizeof(struct ListNode));

    if (list1->val <= list2->val) {
        merged_cur = list1;
        merged_cur->next =  mergeTwoList(list1->next, list2);
        return merged_cur;
    } else {
        merged_cur = list2;
        merged_cur->next = mergeTwoList(list2->next, list1);
        return merged_cur;
    }
}

//풀이2
struct ListNode* mergeTwoList(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* dummy_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy_head -> val = -200;
    dummy_head -> next = NULL;

    struct ListNode* new_cur = dummy_head;
    struct ListNode* temp1 = list1;
    struct ListNode* temp2 = list2;

    while (temp1 != NULL && temp2 != NULL){
        if (temp1->val <= temp2->val){
            new_cur->next = temp1;
            temp1 = temp1->next;
            new_cur = new_cur->next;
        } else {
            new_cur->next = temp2;
            temp2 = temp2->next;
            new_cur = new_cur->next;
        }
    }

    if (temp1 == NULL) {
        new_cur->next = temp2;
    } 

    if (temp2 == NULL) {
        new_cur->next = temp1;
    }

    return dummy_head->next;
}