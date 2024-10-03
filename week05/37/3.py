# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        counts = round(self.countNode(head)/2)
        
        for i in range(counts):
            head = head.next
        return head
        
    def countNode(self, head):
        num = 0
        cur_node = head
        while (cur_node):
            num+=1
            cur_node = cur_node.next
        
        return num