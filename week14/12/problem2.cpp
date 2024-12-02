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
    
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans= new ListNode(0);
        ans->next = head;
        ListNode* p= ans;
        while(p->next && p->next->next){
            ListNode* first= p->next;
            ListNode* second= first->next;

            first->next = second->next;
            second->next = first;
            p->next= second;

            p= first;
        }

        return ans->next;

    }
};