#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
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
    ListNode* middleNode(ListNode* head) {
        
        if (head==nullptr) return nullptr;
        
        ListNode *dummy = new ListNode(); 
        dummy -> next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        while (fast->next && fast->next->next) {
            //fast->next : 1,3,,..
            //fast->next->next : 2,4,,..
            //slow->next : 1,2,/3/ 4,5,
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->next;
    }
};