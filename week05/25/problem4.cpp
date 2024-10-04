struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if ((!list1) && (!list2)) {return list1;}
        else if ((list1==nullptr) && (list2)) {return list2;}
        else if ((list1) && (list2 == nullptr)) {return list1;}
        
        ListNode result(0);
        ListNode* result_curr = &result;

        ListNode* curr_1 = list1; ListNode* curr_2 = list2;
        while(curr_1 && curr_2) {
            if (curr_1->val <= curr_2->val) {
                result_curr->next = curr_1;
                curr_1 = curr_1->next;
            }
            else {
                result_curr->next = curr_2;
                curr_2 = curr_2->next;
            }
            result_curr = result_curr->next;
        }

        if (curr_1) {
            result_curr->next = curr_1;
        }
        else if (curr_2) {
            result_curr->next = curr_2;
        }

        ListNode* final = &result;
        final = final->next;
        return final;
    }
};