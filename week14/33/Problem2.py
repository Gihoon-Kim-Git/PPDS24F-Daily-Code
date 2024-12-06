# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Create a dummy node to simplify edge cases
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        
        # Traverse the list and swap pairs
        while prev.next and prev.next.next:
            # Identify the nodes to be swapped
            first = prev.next
            second = prev.next.next
            
            # Perform the swap
            first.next = second.next
            second.next = first
            prev.next = second
            
            # Move the pointer forward
            prev = first
        
        return dummy.next
