# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head
        val = None
        valNode = None
        while curr != None:
            if val == curr.val:
                valNode.next = curr.next
            else:
                val = curr.val
                valNode = curr
            curr = curr.next
        return head