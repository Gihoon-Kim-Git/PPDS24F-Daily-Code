# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        prev = None
        curr = head

        while curr != None:
            if head.val == val:
                head = head.next
            elif curr.val == val:
                prev.next = curr.next
            prev = curr
            curr = curr.next
            
        return head