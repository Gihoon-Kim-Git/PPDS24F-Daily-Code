# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if not head:
            return head
        
        elemment_list = []
        
        cur_node = head.next
        prev_node = head
        elemment_list.append(head.val)

        while (cur_node):
            if cur_node.val in elemment_list:
                prev_node.next = cur_node.next
            else: 
                elemment_list.append(cur_node.val)
            prev_node = cur_node
            cur_node = cur_node.next
        
        return head
        