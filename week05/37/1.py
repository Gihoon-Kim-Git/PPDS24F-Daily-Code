# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if not head:
            return head
        
        while (head and head.val == val):
            head = head.next
        
        if not head:
            return head
        
        cur_node = head.next
        prev_node = head

        while (cur_node):
            if cur_node.val == val:
                prev_node.next = cur_node.next
            prev_node = cur_node
            cur_node = cur_node.next
        
        return head
        