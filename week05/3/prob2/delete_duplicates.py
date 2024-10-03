# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def deleteDuplicates(self, head):
    
    # empty or one node
    if not head or not head.next:
        return head

    # initialixation: traversal pointer
    curr = head

    # traversal
    while curr and curr.next:
        if curr.val == curr.next.val:
            # bypass next node
            curr.next = curr.next.next
        else:
            # move pointer to next node
            curr = curr.next

    return head