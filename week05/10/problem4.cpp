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

// using recursion
class Solution { 
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
            
        ListNode* ans=nullptr;
        
        if(list1->val < list2-> val){
            ans=list1;
            ans->next=mergeTwoLists(list1->next ,list2);
        } else {
            ans=list2;
            ans->next=mergeTwoLists(list1,list2->next);
        }
        return ans;
    }

};

    /*
    if (!list1 || !list2){
        return list1 ? list1 : list2; //condition ? result_if_true : result_if_false
    } 
    if (list1->val > list2->val){
        swap(list1, list2);
    }
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
    }
    */