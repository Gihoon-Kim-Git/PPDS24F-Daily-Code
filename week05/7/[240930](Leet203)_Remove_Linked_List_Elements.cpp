//문제 : 어떤 Singlyl linked list의 head가 주어졌을 때, SLL에서 특정 val값 가지는 node를 모두 제거&& return new head

/*문제풀이1 
    1. dummy_head 선언 : ListNode(-1, head);
    2. prev, cur 움직이면서 target_val에 대한 처리
        cur.val == target_val일 때는, prev->next = cur->next로 cur을 뛰어넘도록 연결관계 수정 후, pev는 고정하고, cur만 한칸씩 이동하며 탐색
        else : prev.next = cur 이어주고, prev, cur 함께 update
    3. return dummy_head->next;
*/

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int target_val) {
        ListNode new_dummy = ListNode(-1, head);
        ListNode* dummy_head = &new_dummy;
        ListNode* prev = dummy_head;
        ListNode* cur = head;
        
        while (cur != nullptr){
            if (cur->val == target_val){
                prev ->next = cur->next;
                cur = cur->next;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy_head->next;
    }
};