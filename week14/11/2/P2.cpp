#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        // Initialize the new head of the list
        ListNode* new_head = head->next;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        // Traverse the list in pairs
        while (curr && curr->next) {
            ListNode* first = curr;
            ListNode* second = curr->next;
            
            // Swap the nodes
            first->next = second->next;
            second->next = first;
            
            // Connect the previous node to the second node of the swapped pair
            if (prev) {
                prev->next = second;
            }
            
            // Move prev and curr two steps ahead
            prev = first;
            curr = first->next;
        }
        
        return new_head;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution solution;
    
    // Create a sample linked list
    vector<int> vals = {1, 2, 3, 4};
    ListNode* head = createList(vals);
    
    // Swap pairs and print the result
    ListNode* result = solution.swapPairs(head);
    printList(result);
    
    return 0;
}
