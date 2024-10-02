"""문제
SLL의 head가 주어졌을 때, SLL의 middle node를 return
middle node가 두 개 있을 때는, second middle node를 return
"""
"""constraint
    SLL 노드들의 갯수는 [1,100]
    1 <= Node.val <= 100
"""

"""문제풀이
    1. slow, fast를 관리. slow는 한칸씩, fast는 두칸씩.
    2. fast.next가 None(SLL 길이가 홀수일 때), fast가 None일 때(SLL길이가 짝수일 때)인 순간에
        slow를 출력하면, 그것이 구하려는 middle node임.
"""

#Definition for SLL
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def middleNode(self, head) :
        
        slow = head
        fast = head
        
        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next
            
        return slow