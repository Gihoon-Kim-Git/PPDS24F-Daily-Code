# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        now = head
        prev = None
        
        while now:
            if now.val == val:
                if prev == None:
                    # prev == None인 경우, now는 head에 위치
                    head = now.next
                else:
                    # prev != None인 경우, now는 중간 노드
                    prev.next = now.next
                    prev = now
            else:
                prev = now
            now = now.next
            
        return head




        