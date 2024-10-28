# Definition for singly-linked list.
from typing import Optional

        
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def printLL(head: ListNode):
    current = head
    while current:
        print(current.val, end = '->')
        current = current.next

def makeLL(lst: list) -> ListNode:
    sentinel = ListNode()
    while lst:
        a = lst.pop()
        new = ListNode(a)
        new.next = sentinel.next
        sentinel.next = new

    return sentinel.next

def removeElements(head: Optional[ListNode], val: int) -> Optional[ListNode]:
        
        sentinel = ListNode(val = 0, next = head)    
        current = sentinel
        next = current.next
        
        while next:
            if next.val == val:
                current.next = next.next
                next = current.next
            else:
                current = next
                next = current.next

        return sentinel.next
    
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        
        sentinel = ListNode(val = 0, next = head)    
        current = sentinel
        next = current.next
        
        while next:
            if next.val == val:
                current.next = next.next
                next = current.next
            else:
                current = next
                next = current.next

        return sentinel.next
    
if __name__ == '__main__':
    LL = makeLL([7,7,7,7])
    LL = removeElements(LL, 7)
    printLL(LL)
    