## LeetCode 203. Remove Linked List Elements

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if not head:
            return
        dummyNode = ListNode(0)
        dummyNode.next = head

        curNode = head
        prevNode = dummyNode
        while curNode is not None:
            if curNode.val == val:
                prevNode.next = curNode.next
                curNode = curNode.next
            else:
                prevNode = curNode
                curNode = curNode.next
                
        return dummyNode.next