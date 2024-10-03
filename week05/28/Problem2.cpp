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
        if(!head){return nullptr;}
        if(!(head->next)){return head;}

        set<int> uniqueSet;
        ListNode* cur = head;
        while(cur){
            uniqueSet.insert(cur->val);
            cur = cur->next;
        }

        ListNode* back = new ListNode();
        for(auto i=uniqueSet.rbegin(); i!=uniqueSet.rend(); i++){
            ListNode* front = new ListNode();
            back->val = *i;
            front->next = back;
            back = front; 
        }

        return back->next;
    }
};