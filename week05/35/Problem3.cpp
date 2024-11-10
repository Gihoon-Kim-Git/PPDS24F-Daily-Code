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
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode *curr = head;
        ListNode *temp;
        while(curr)
        {
            size++;
            curr = curr->next;
        }

        int idx = size/2;
        curr = head;
        int i = 0;
        while(i < idx)
        {
            i++;
            curr = curr->next;
        }
        return curr;
    }
};