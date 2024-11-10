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
    ListNode* middleNode(ListNode* head) {
       ListNode* now = head;
       ListNode* half_head = head;
        int chk = 0;
        while(now){
            if(chk % 2 == 1){
                half_head = half_head->next;
            }
            now = now->next;
            chk++;
        }
        return half_head;
    }
};