
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* curr = head;
        if (!curr) {return head;}
        ListNode* follow = curr->next;
        int size = 1;

        while (follow) {
            size++;
            curr = follow; follow = follow->next;
        }
        
        int target = 1;
        ListNode* curr2 = head;
        while (target != (size/2) + 1) {
            target++;
            curr2 = curr2->next;
        }

        return curr2;
    }
};