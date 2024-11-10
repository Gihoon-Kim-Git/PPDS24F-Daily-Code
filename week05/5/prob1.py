# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        sentinel = ListNode(-1, None)
        prev = sentinel
        curr = head
        while curr:
            if curr.val == val:
                prev.next = None
                # prev = prev
                curr = curr.next
            else:
                prev.next = curr
                prev = curr
                curr = curr.next
        return sentinel.next
