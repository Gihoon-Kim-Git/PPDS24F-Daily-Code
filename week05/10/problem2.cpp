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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr) return nullptr;
        
        ListNode* prev = head;
        ListNode* temp = head->next;

        while(temp){
            if(prev->val == temp->val) {
                prev->next = temp->next;
            }else{
                prev = temp;
            } temp = temp->next;
        }
        return head;
    }
};