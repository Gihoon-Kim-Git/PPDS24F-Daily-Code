# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
def mergeTwoLists(self, list1, list2):
    # dummy node
    # helps avoid dealing with edge cases like initializing new list's head
    dummy = ListNode(0)
    curr = dummy

    # traverse both lists
    while list1 and list2:
        # add nodes
        if list1.val <= list2.val:
            curr.next = list1
            list1 = list1.next
        else:
            curr.next = list2
            list2 = list2.next
        # move curr pointer
        curr = curr.next

    # append nodes in remaining list
    if list1:
        curr.next = list1
    elif list2:
        curr.next = list2

    return dummy.next