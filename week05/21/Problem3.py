# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        
        cnt = 1
        cur = head

        if cur.next is None:
            return head

        else:
            while cur.next is not None:
                cur = cur.next
                cnt += 1
            
            cur = head
            mid = cnt//2 - 1
            temp = 0

            while temp != mid:
                cur = cur.next
                temp += 1

            newhead = cur.next
            cur.next = None
            head = newhead

        return head
        
