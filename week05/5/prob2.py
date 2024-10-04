# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        else:
            prev = head
            curr = head.next
            while prev and curr:
                if prev.val == curr.val:
                    prev.next = None
                    curr = curr.next
                else:
                    prev.next = curr
                    prev = curr
                    curr = curr.next
            return head
