# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """

        if head is None:
            return None

        while head.val == val and head.next is not None:
            head = head.next

        if head is None or head.val == val:
            return None

        cur = head
        while cur.next is not None:
            if cur.next.val == val:
                cur.next = cur.next.next 
            else:        
                cur = cur.next
        return head
        