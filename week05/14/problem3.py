## Problem 3. [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=problem-list-v2&envId=linked-list)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        N = 0
        nhead = head
        while nhead.next:
            nhead = nhead.next
            N += 1
        
        half = N//2 + N%2
        while half > 0:
            head = head.next
            half -= 1
        
        return head