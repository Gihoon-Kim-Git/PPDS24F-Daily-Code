# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        # Initialize a dummy node to simplify edge cases like removing the head node
        dummy = ListNode(next=head)
        current = dummy

        # Traverse through the linked list
        while current and current.next:
            if current.next.val == val:
                # Skip the node with the target value
                current.next = current.next.next
            else:
                # Move to the next node
                current = current.next
        
        # Return the new head, which is dummy.next
        return dummy.next