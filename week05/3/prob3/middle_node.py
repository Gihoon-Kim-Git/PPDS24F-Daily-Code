# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
def middleNode(self, head):
    
    # initialization: two pointers
    slow = head # 1 step
    fast = head # 2 steps

    # traversal
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    return slow

'''
In an even-length list, the fast pointer reaches the end
after an odd number of iterations (i.e., it steps through pairs of nodes).
The moment the fast pointer cannot move forward by two steps
(i.e., when it reaches the end or null),
the slow pointer has just passed the first middle node and is now on the second middle node.
'''