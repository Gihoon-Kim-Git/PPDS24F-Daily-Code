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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* now = head;
        ListNode* prev = NULL;

        while(now){
            if(now->val == val){
                if(prev == NULL){
                    // now is head node
                    head = now->next;
                }else{
                    // now is not head node
                    prev->next = now->next;
                    prev = now;
                }
            }else{
                prev = now;
            }
            now = now->next;
        }
        return head;
    }
};