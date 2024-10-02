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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* now = head;
        ListNode* prev = nullptr;

        while(now){
            if(prev != nullptr && now->val == prev->val){
                prev->next = now->next;
            }else{
                prev = now;
            }
            now = now->next;
        }
        return head;
    }
};