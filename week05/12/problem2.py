# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr=head
        while(curr and curr.next):
            nxt = curr.next
            while(nxt!= None and curr.val==nxt.val ):
                nxt = nxt.next
            curr.next= nxt
            curr=curr.next
        return head


        