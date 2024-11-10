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
    void smaller(ListNode* l1, ListNode* l2, ListNode* pos){
        ListNode* cur = pos;
        if(l1 == nullptr){
            cur->next = l2;
            return;
        }
        if(l2 == nullptr){
            cur->next = l1;
            return;
        }

        if(l1->val < l2->val){
            cur->next = l1;
            smaller(l1->next, l2, cur->next);
        }
        else{
            cur->next = l2;
            smaller(l1, l2->next, cur->next);
        }
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = new ListNode();
        smaller(list1, list2, result);
        return result->next;
    }
};