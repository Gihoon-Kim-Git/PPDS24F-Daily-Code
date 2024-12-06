from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        i=0
        curr = head
        while(curr):
            if not curr or not curr.next:
                # print("check323")
                return head
            node1 = curr
            node2 = curr.next
            node1.next = node2.next
            node2.next = node1
            # print(i)
            if i == 0:
                head = node2
                i += 1
                # print(i)
            else:
                # print("check")
                prev.next = node2
            prev = node1
            curr = curr.next
        return head

def printNodes(node:ListNode):
    crnt_node = node
    while crnt_node is not None:
        print(crnt_node.val , end= ' ')
        crnt_node = crnt_node.next


sol = Solution()
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)


node = sol.swapPairs(head)
printNodes(node)



