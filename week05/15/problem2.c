struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *curr = head;    
    while (curr && curr->next) {        
        if (curr->val == curr->next->val) curr->next = curr->next->next;        
        else curr = curr->next;
    }    
    return head;
}