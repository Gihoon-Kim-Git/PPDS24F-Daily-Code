
# Definition for singly-linked list.
from typing import Optional

        
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        p1 = list1
        p2 = list2 

        sentinel = ListNode()
        output = sentinel

        while p1 and p2:
            if p1.val < p2.val:
                output.next = p1
                p1 = p1.next
            else :
                output.next = p2
                p2 = p2.next
            output = output.next

        while p1 :
            output.next = p1
            p1 = p1.next
            output = output.next

        while p2 :
            output.next = p2
            p2 = p2.next
            output = output.next

        return sentinel.next
