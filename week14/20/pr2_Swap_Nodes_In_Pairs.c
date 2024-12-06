//  * Definition for singly-linked list.

  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;
    
    while(curr && curr->next){
        prev -> next = curr->next;
        prev = curr;
        struct ListNode* temp = curr->next->next;
        curr->next->next = curr;
        curr->next = temp;
        curr = temp;
    }
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}