from collections import Optional

# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        current = head
    
        while current and current.next:
            next_node = current.next
            
            current.next = next_node.next
            next_node.next = current
            prev.next = next_node
            
            prev = current
            current = current.next
        
        return dummy.next