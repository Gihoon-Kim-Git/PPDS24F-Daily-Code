# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        prev = None
        curr = head
        while curr and curr.next:
            if not prev:
                temp = curr.next
                curr.next = curr.next.next
                temp.next = curr
                head = temp
            else:
                temp = curr.next
                curr.next = curr.next.next
                temp.next = curr
                prev.next = temp

            prev = curr
            curr = curr.next

        return head