
// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

// Example 1:

// Input: head = [1,2,3,4]

// Output: [2,1,4,3]

// Explanation:



// Example 2:

// Input: head = []

// Output: []

// Example 3:

// Input: head = [1]

// Output: [1]

// Example 4:

// Input: head = [1,2,3]

// Output: [2,1,3]




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
    ListNode* swapPairs(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* node_prev = nullptr;
        ListNode* node_1 = head;
        ListNode* node_2 = head->next;
        ListNode* node_next;
        if (node_2->next != nullptr) {
            node_next = node_2->next;
        }

        head = node_2;

        while (true){

            if (node_prev != nullptr) {
                node_prev->next = node_2;
            } 

            node_1->next = node_next;
            node_2->next = node_1;

            if (node_next == nullptr || node_next->next == nullptr) {
                break;
            }

            node_prev = node_1;
            node_1 = node_next;
            node_2 = node_next->next;
            node_next = node_2->next;

        }
        
        return head;
    }
};