# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p1= head
        if p1.next==None:
            return p1
        p2 = head.next.next
        while p2 and p2.next:
            p1= p1.next
            p2= p2.next.next
        return p1.next