//  * Definition for singly-linked list.
struct ListNode {
      int val;
      struct ListNode *next;
 };
 
struct ListNode* middleNode(struct ListNode* head) {
    if(!head || !head->next) return head;
    
    int size = 0;
    struct ListNode* arr[100];

    struct ListNode* temp = head;
    while(temp){
        arr[size++] = temp;
        temp = temp -> next;
    }
    int mid = size / 2;
    return arr[mid];
}