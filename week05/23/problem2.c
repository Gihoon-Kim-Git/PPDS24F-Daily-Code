/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode*k=head;
    struct ListNode*z;
    if(head==NULL)
    return head;
    int i;
    for(i=0;i<5;i++)
    {while(k->next!=NULL)
    {
        z=k;
        k=k->next;
        if(z->val==k->val)
        {
            z->next=k->next;
        }
    }
    k=head;
}
    return head;
}