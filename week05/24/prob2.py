from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize the current pointer to the head of the list
        current = head

        # Traverse the list until the end
        while current and current.next:
            if current.val == current.next.val:
                # If the current node value is equal to the next node's value, skip the next node
                current.next = current.next.next
            else:
                # Otherwise, move to the next node
                current = current.next
        
        # Return the head of the modified list
        return head

if __name__ == "__main__":
    sol = Solution()
    head = ListNode(1, ListNode(1, ListNode(2, ListNode(3, ListNode(3)))))
    result = sol.deleteDuplicates(head)