#include<iostream>
#include <cmath>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ptr1 = list1;
        ListNode *ptr2 = list2;
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        ListNode *curr;

        while(ptr1 && ptr2)
        {
            if(ptr1->val <= ptr2->val)
            {
                curr = new ListNode(ptr1->val);
                ptr1 = ptr1->next;
            }
            else
            {
                curr = new ListNode(ptr2->val);
                ptr2 = ptr2->next;
            }
            prev->next = curr;
            prev = curr;
            //curr = curr->next;
        }
        if(!ptr1 && ptr2)
        {
            prev->next = ptr2;
        }
        else if(ptr1 && !ptr2)
        {
            prev->next = ptr1;
        }
        return dummy->next;

    }
};