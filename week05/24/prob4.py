# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # Create a dummy node to serve as the head of the merged list
        dummy = ListNode()
        current = dummy
        
        # Traverse both lists until one is fully processed
        while list1 and list2:
            if list1.val <= list2.val:
                # Append the node from list1
                current.next = list1
                list1 = list1.next
            else:
                # Append the node from list2
                current.next = list2
                list2 = list2.next
            # Move the current pointer to the next node
            current = current.next
        
        # If one list is still not fully processed, append the remaining part
        if list1:
            current.next = list1
        elif list2:
            current.next = list2
        
        # Return the merged list starting from the node next to dummy
        return dummy.next