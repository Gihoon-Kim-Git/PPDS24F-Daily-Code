# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next : return head
        # Sentinel Node 이용..
        dummy = ListNode(999,head)
        prev = dummy
        curr = head
        while curr and curr.next :
            prev.next = curr.next # sentinel -> 2
            prev = curr # sentinel:1
            temp = curr.next.next
            curr.next.next = curr
            curr.next = temp
            curr = temp # curr -> 3
        return dummy.next
        # # recursive
        # if not head or not head.next:
        #     return head

        # first_node, second_node = head, head.next

        # first_node.next = self.swapPairs(second_node.next)
        # second_node.next = first_node

        # return second_node