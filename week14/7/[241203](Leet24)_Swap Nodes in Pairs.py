""""Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)"""

#★ 풀었지만 스스로도 헷갈림!!!#

# prev, cur, temp로 바꾸고, cur = cur.next.next로 하면 더 간단히 됨.


""""Constraints:
    The number of nodes in the list is in the range [0, 100].
    0 <= Node.val <= 100"""
    
"""아이디어
    prev, cur, nxt를 유지하면서 처음부터 끝까지 나아간다.
    prev, cur이 모두 NULL이 아닐 때 (그냥 이 조건으로 하면 필요한 때보다 더 많이 바꾼다. 조건을 어떻게 수정해야 할까.)
        prev.next를 cur.next로
        cur.next를 prev로 하면 되지 않나!?
        그리고 cur = nxt로 수정.
                nxt = cur.next
                prev가 이전 prev랑 달라질 때만 움직이면 될 거 같은데.
    cur.next가 NULL이면 끝.
    
    <초기세팅>
    new_head 반환을 위한 sentinel 정의
    new_head = ListNode(-1, head)
    
    pre_prev = NULL (None)
    prev = NULL
    cur = head
    nxt = cur.next (항상 존재하는 것이 아니기 떼문에 예외처리 필요)
    
    cur.next != NULL인 동안 반복
        prev != pre_prev 인 때만 swap
            #swap
            prev.next = nxt
            cur.next = prev
            pre_prev.next = cur
            
            # cur을 다음으로 바꿔줌
            cur = nxt
            nxt = nxt.next
            pre_prev = prev
            
        prev == pre_prev이면 
            prev = cur
            cur = nxt
            nxt = nxt.next
            pre_prev.next = cur
    
    while문만 거치면, 마지막 노드와 이전 노드를 바꿔야할 때 작동못함.
    따라서 마지막 노드와 이전 노드를 바꿔줘야 하는 경우에 추가 처리 필요.
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if head == None :
            return head
        
        new_head  = ListNode(-1, head)

        pre_prev = new_head
        prev = new_head
        cur = head
        if cur.next != None:
            nxt = cur.next
            
        while cur.next != None :
            if prev != pre_prev :
                pre_prev.next = cur
                prev.next = nxt
                cur.next = prev
                
                cur = nxt
                nxt = nxt.next
                pre_prev = prev
                
            else : # prev == pre_prev
                prev = cur
                cur = nxt
                nxt = nxt.next
                pre_prev.next = cur            
        
        # 만약 cur이 None이 아니고 prev != pre_prev이면 (마지막 요소 처리를 위한)
        if cur!= None and prev != pre_prev :
                pre_prev.next = cur
                prev.next = nxt
                cur.next = prev


        return new_head.next
    
#%% Recursion
def swapPairs(self, head):
    if not head or not head.next :
        return head
    curr =head.next
    head.next = self.swapPairs(head.next.next) # head.next.next를 새로운 head로 recursive하게 넘겨줌으로써 뒷부분을 계속해서 pair-swap해서 정렬해주는 과정
    curr.next = head
    
    return curr