# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # Dummy node to simplify edge cases
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        
        # Traverse the list
        while prev.next and prev.next.next:
            # Identify the nodes to swap
            first = prev.next
            second = prev.next.next
            
            # Swap the nodes
            first.next = second.next
            second.next = first
            prev.next = second
            
            # Move to the next pair
            prev = first
        
        return dummy.next

        