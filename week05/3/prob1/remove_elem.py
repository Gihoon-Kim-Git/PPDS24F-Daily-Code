# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def removeElements(head, val: int):
    # initialization: dummy node
    # dummy: helps in cases where the head node itself needs to be removed
    dummy = ListNode(0)
    dummy.next = head

    # initialization: two pointers
    prev = dummy
    curr = head

    # traverse linked list
    while curr:
        if curr.val == val:
            # skip curr node
            prev.next = curr.next
        else:
            # move prev node to curr
            prev = curr
        # move curr node to next
        curr = curr.next

    # return new head
    return dummy.next