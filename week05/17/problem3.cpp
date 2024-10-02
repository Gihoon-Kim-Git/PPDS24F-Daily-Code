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

        // 1 -> 1
        // 2 -> 2
        // 3 -> 2
        // 4 -> 3
        // 5 -> 3
        // 6 -> 4

        // null 나올 때까지 count 하나씩 올려가면서
        // 짝수일 때마다 하나씩 next로 옮겨주면 됨

        ListNode* curr = head;
        ListNode* mid = head;
        int count = 1; 

        while (curr != nullptr){
            if (count % 2 == 0){
                mid = mid->next;
            }
            curr = curr->next;
            count++;
        }
        return mid;
    }
};