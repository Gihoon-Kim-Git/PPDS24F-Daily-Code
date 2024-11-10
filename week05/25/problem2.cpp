
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
        ListNode* curr = head;
        if (!curr) {return head;}
        ListNode* follow = curr->next;

        while (follow) {
            if (follow->val == curr->val) {
                curr->next = follow->next;
                follow = follow->next;
            }
            else {
                curr = curr->next;
                follow = follow->next;
            }
        }
        return head;
    }
};