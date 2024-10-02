# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        start = head
        
        while l1 or l2:
            if l1 and l2:
                if l1.val<=l2.val:
                    head.next = l1
                    l1 = l1.next
                else:
                    head.next = l2
                    l2=l2.next
            elif l1 and not l2:
                head.next = l1
                break
            else:
                head.next = l2
                break
            
            head = head.next
        
        return start.next
        
        