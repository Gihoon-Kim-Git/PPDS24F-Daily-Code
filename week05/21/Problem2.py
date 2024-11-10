# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        
        else:
            cur = head
            if cur.next is None:
                return head
            while cur.next is not None:
                if cur.val == cur.next.val:
                    if cur.next.next is not None:
                        cur.next = cur.next.next
                    else:
                        cur.next = None
                else:
                    cur = cur.next
            
            return head
            
        