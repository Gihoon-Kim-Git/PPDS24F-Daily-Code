#include <iostream>

using namespace std;

/* Definition for singly-linked list. */
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
        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        if (head == nullptr) return nullptr;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
                curr = curr->next;  
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr){return nullptr;}
        if (head != nullptr && head -> next == nullptr){return head;}

        ListNode* prev = head;
        ListNode* curr = head -> next;

        while (curr != nullptr){
            if (curr -> val == prev -> val){
                prev -> next = curr -> next;
                curr = curr -> next;
            }
            else {
                prev = prev -> next;
                curr = curr -> next;
            }
        }
        return head;
    }

    ListNode* middleNode(ListNode* head) {
        if (head == nullptr){return nullptr;}

        int n = 0;
        ListNode* curr = head;

        while (curr != nullptr){
            curr = curr -> next;
            n++;
        }

        int m = n / 2;
        ListNode* ans = head;

        while (m > 0){
            ans = ans -> next;
            m--;
        }

        return ans;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*base case*/
        if (list1==nullptr) {return list2;}
        if (list2==nullptr) {return list1;}

        /*recursive*/
        if (list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};


int allSums_onetwothree(int n){
    /* base case */
    if (n==0){return 0;}
    else if (n==1){return 1;}
    else if (n==2){return 2;}
    else if (n==3){return 4;}
    else {
    /* recursive */
    return allSums_onetwothree(n-1) + allSums_onetwothree(n-2) + allSums_onetwothree(n-3);
    }
}