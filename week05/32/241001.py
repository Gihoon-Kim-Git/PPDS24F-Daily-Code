## LeetCode 83. Remove Duplicates from Sorted List

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head):
        dummy = ListNode(101)
        dummy.next = head
        prev = dummy
        cur = head        

        if cur == None or cur.next == None:
            return cur

        while (cur):
            if (prev.val == cur.val):
                prev.next = cur.next
                cur = cur.next
            else:
                prev = cur
                cur = cur.next
        return dummy.next