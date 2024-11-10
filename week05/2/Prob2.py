# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        now = head
        prev = None
        while now:
            chkval = now.val
            if prev != None and prev.val == now.val:
                prev.next = now.next
            else:
                prev = now
            now = now.next
        
        return head

