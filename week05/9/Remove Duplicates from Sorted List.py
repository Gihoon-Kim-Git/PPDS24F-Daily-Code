from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:

        current = head

        if not current:
            return head

        visited = current.val
        
        
        next = current.next

        while next:
            
            if next.val == visited:
                current.next = next.next 
                next = current.next

            else :
                visited = next.val
            
                current = next
                next = current.next
        
        return head

def printLL(head: ListNode):
    current = head
    while current:
        print(current.val,"-> ",end='')
        current = current.next

def append(head: ListNode, newval: ListNode):
    newNode = ListNode(newval)
    next = head.next
    head.next = newNode
    newNode.next = next
    return head

if __name__ == '__main__':
    head = ListNode(7)
    append(head,7)
    append(head,7)
    append(head,7)
    solution = Solution()
    printLL(solution.deleteDuplicates(head))
    pass
        