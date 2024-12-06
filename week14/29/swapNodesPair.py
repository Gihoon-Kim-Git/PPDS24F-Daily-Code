"""
<Swap Nodes in Pairs>
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def swap_pairs_recursive(head):
    # Base case: if less than two nodes, return head
    if not head or not head.next:
        return head
    
    # Swap the first two nodes
    first = head
    second = head.next
    
    # Recursively swap the rest of the list
    first.next = swap_pairs_recursive(second.next)
    second.next = first
    
    return second

def print_list(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    print(result)

# Create linked list: 1 -> 2 -> 3 -> 4
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
print_list(head)  # Original list: [1, 2, 3, 4]
head = swap_pairs_recursive(head)
print_list(head)  # Swapped list: [2, 1, 4, 3]
