# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        result = ListNode()
        # if list is null
        if list1 == None:
            return list2
        if list2 == None:
            return list1
        
        # check val
        if list1.val < list2.val:
            result = list1
            result.next = self.mergeTwoLists(list1.next, list2)
        else:
            result = list2
            result.next = self.mergeTwoLists(list1, list2.next)
        
        # return node
        return result
