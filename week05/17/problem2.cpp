/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // sorted list에서 중복 값을 제거해야 함. 
        // 중복 값의 경우 무조건 연속하여 등장할 수 밖에 없음. 
        // 이전 값과 동일할 경우, 해당 node를 제거 

        // node 0개 or 1개
        if (head == nullptr || head->next == nullptr){
            return head;
        }

        // node 2개 이상
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr){
            if (curr->val == prev->val){
                prev->next = curr->next;
                curr = curr->next;
            } else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};