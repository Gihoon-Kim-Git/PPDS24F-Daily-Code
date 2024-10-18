/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        } else {
            ListNode* prev = head;
            ListNode* curr = head->next;

            while (prev && curr) {
                if (prev->val == curr->val) {
                    prev->next = nullptr;
                    curr = curr->next;
                } else {
                    prev->next = curr;
                    prev = curr;
                    curr = curr->next;
                }
            }

            return head;
        }
    }
};
