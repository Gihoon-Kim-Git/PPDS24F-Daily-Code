// LeetCode 21. Merge Two Sorted Lists


// Definition for singly-linked list.
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
        ListNode * dummy = new ListNode();
        ListNode * cur = dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
                cur = cur->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
                cur = cur->next;
            }
        }
        if (list1) {
            cur->next = list1;
        }
        if (list2) {
            cur->next = list2;
        }
        return dummy->next;
    }
};