# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        # 아무것도 없는 case
        if not head : return head
        # 처음부터 target val이 나오는 case
        while head and head.val == val :
            head = head.next
        fast = head
        # 일반적인 case
        while fast and fast.next :
            if fast.next.val == val:
                fast.next = fast.next.next
            else : fast = fast.next
        return head