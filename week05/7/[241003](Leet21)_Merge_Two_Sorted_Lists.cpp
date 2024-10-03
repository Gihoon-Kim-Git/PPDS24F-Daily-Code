/*문제
2개의 sorted SLL이 있을 때, 이것들을 하나의 sorted SLL로 변환.(non-decreasing order)
return the head of the merged linked list.*/

/*Constraint
    -100 <= Node.val <=100
    list1, list2 are sorted in non-decreasing order
    # of nodes : [0,50]*/

/*문제풀이1
    1. dummy_head에다가 하나씩 .next로 연결.
    2. 연결 간, list1, list2의 요소 중 val이 작은 것을 골라서 연결. (연결을 위한 현재위치관리는 cur_new)
        - temp1, temp2로 관리.
        - temp1 <= temp2 : cur_new->next = temp1, temp1 = temp1->next, cur_new = cur_new->next
        - temp1 > temp2 : 윗줄의 temp1을 temp2로.
    2 반복조건 : temp1, temp2 모두가 list 끝에 도달하지 않는동안 (temp1 == nullptr && temp2 == nullptr)
    3. 2탈출 후, 아직 list 끝에 도달하지 못한 temp의 경우, cur_new->next로 연결.
    4. return dummy_head.next
*/

/*문제풀이2 : recursion
    1. list1, list2를 넣은 함수 결과로 merged_list의 head를 반환하는 형태.
    2. Base case : list1이 empty 이거나 list2가 empty, list1이 empty면 list2를 반환, list2가 empty면 list1 반환 (input의 list1, list2 자체가 head인 상태.)
    3. Recursive case : mergeTwoLists 함수 활용.
        - merged_head 만들어주고, head로 list1, list2 중 작은 것을 할당. (if list1.val <= list2.val)
        - merged_head->next 를 mergeTwoLists(할당->next, 반대list) 결과로
        - return merged_head;. 
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 문제풀이1
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode new_head = ListNode(-200);
        ListNode* dummy_head = &new_head;

        ListNode* cur_new = dummy_head;
        ListNode* temp1 = list1; 
        ListNode* temp2 = list2; 

        while (temp1 != nullptr && temp2 != nullptr){
            if (temp1->val <= temp2->val){
                cur_new->next = temp1;
                temp1 = temp1->next;
                cur_new = cur_new->next;
            } else {
                cur_new->next = temp2;
                temp2 = temp2->next;
                cur_new = cur_new->next;
            }
        }

        if (temp1 != nullptr){
            cur_new -> next = temp1;
        } 
        if (temp2 != nullptr){
            cur_new -> next = temp2;
        }
        
        return dummy_head->next;
    }

    //문제풀이2
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        // Base case : nullptr인 경우 반대 list반환
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        //Recursive case
        ListNode* merged_head = nullptr;
        if (list1->val <= list2->val){
            merged_head = list1;
            merged_head->next = mergeTwoLists(list1->next, list2);
            return merged_head;
        } else {
            merged_head = list2;
            merged_head->next = mergeTwoLists(list2->next, list1);
            return merged_head;
        }
    }
};
