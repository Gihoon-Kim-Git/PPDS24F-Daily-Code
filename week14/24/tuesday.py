# swap nodes in pairs

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        dummy = ListNode(0, head)
        prev = dummy

        while prev.next and prev.next.next:
            first = prev.next
            second = prev.next.next

            first.next = second.next
            second.next = first
            prev.next = second

            prev = first
        
        return dummy.next


if __name__ == "__main__":
    sol = Solution()
    # 1->2->3->4
    head1 = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    result1 = sol.swapPairs(head1) 
    output1 = []
    while result1:
        output1.append(str(result1.val))
        result1 = result1.next
    print("->".join(output1))
    
    # 1,2,3
    head2 = ListNode(1, ListNode(2, ListNode(3)))
    result2 = sol.swapPairs(head2)
    output2 = []
    while result2:
        output2.append(str(result2.val))
        result2 = result2.next
    print("->".join(output2))
