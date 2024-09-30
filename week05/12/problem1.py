# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        tmp = dummy
        curr = head
        while curr:
            if curr.val == val:
                tmp.next = curr.next
            else:
                tmp = tmp.next
            curr = curr.next  
        
        return dummy.next
                
        
            