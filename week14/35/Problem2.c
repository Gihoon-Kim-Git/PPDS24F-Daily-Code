/**
 * Definition for singly-linked list.
24. Swap Nodes in Pairs
Solved
Medium
Topics
Companies
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *swapPairs(struct ListNode *head)
{
    if (!head)
    {
        return head;
    }
    if (!head->next)
    {
        return head;
    }
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *prev = dummy;
    struct ListNode *curr = head;
    // struct ListNode *temp = head->next;

    while (curr && curr->next)
    {
        struct ListNode *temp = curr->next;

        prev->next = temp;
        curr->next = temp->next;
        temp->next = curr;

        prev = curr;
        curr = curr->next;
    }
    return dummy->next;
}