# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize two pointers, slow and fast
        slow = head
        fast = head
        
        # Traverse the list
        while fast and fast.next:
            slow = slow.next        # slow moves one step
            fast = fast.next.next   # fast moves two steps
        
        # When fast reaches the end, slow will be at the middle
        return slow