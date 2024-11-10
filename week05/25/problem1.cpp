
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
        ListNode* curr = head;
        if (!curr) {return head;}

        ListNode* follow = curr->next;
        while (follow) {
            if (follow->val == val) {
                curr->next = follow->next;
                follow = follow->next;
            }
            else {
                curr = curr->next;
                follow = follow->next;
            }
        }

        if (head->val == val) {head = head->next;}
        return head;
    }
};