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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr){
            if (curr->val == val){ 
                if (curr == head){ 
                    head = curr->next;
                } else{
                    prev->next = curr->next;
                }
                curr = curr->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};