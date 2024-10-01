# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        now = head
        half_head = head
        chk = 0
        while now:
            if chk % 2 == 1:
                half_head = half_head.next
            now = now.next
            chk += 1
        return half_head

