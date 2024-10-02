# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head
        curr2 = head
        while curr2.next != None:
            if curr2.next.next :
                curr2 = curr2.next.next
                curr = curr.next
            else:
                return curr.next
        return curr