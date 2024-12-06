class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def swap_pairs(head):
    """
    Swap every two adjacent nodes in a linked list and return its head.
    """
    # Dummy node to simplify edge cases
    dummy = ListNode(0)
    dummy.next = head
    prev = dummy

    while prev.next and prev.next.next:
        # Nodes to be swapped
        first = prev.next
        second = prev.next.next
        
        # Swapping the nodes
        first.next = second.next
        second.next = first
        prev.next = second
        
        # Move to the next pair
        prev = first

    return dummy.next

# Example usage:
# Create a linked list: 1 -> 2 -> 3 -> 4
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
# Apply the function
result = swap_pairs(head)

# Collect results for display
result_list = []
while result:
    result_list.append(result.val)
    result = result.next

result_list
