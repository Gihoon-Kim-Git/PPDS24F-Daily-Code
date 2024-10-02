# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        #Recursive
        def merge(lst1,lst2,node):
            if lst1 and lst2 :
                if lst1.val < lst2.val:
                    node.next = lst1
                    lst1 = lst1.next
                else :
                    node.next = lst2
                    lst2 = lst2.next
                node = node.next
                return merge(lst1,lst2,node)
            elif lst2:
                node.next = lst2
            else : node.next = lst1
        node = ListNode()
        temp = node
        merge(list1,list2,temp)
        return node.next



