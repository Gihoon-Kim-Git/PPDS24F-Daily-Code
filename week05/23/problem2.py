# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # need to iterate the linked list and store that in hashmap :
        cur = head 
        hashmap = {}
        head2 = None
        finl_head  = None
        while cur is not None:
            if cur.val in hashmap:
                
                cur = cur.next
            
            else:

                hashmap[cur.val] = 0

                if head2 is None:

                    head2 = ListNode(cur.val)
                    finl_head = head2
                    
                    

                else:    
                    node  =  ListNode(cur.val)

                    
                    
                    while head2.next is not None:
                        head2 = head2.next
                        

                    head2.next = node    

                cur = cur.next 
        
        return finl_head