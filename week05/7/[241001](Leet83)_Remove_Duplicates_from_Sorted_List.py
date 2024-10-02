"""문제 : sorted_SLL의 head가 주어졌을 때, 같은 값을 가지는 노드들이 여러 개 있으면 하나만 남기고 나머지는 삭제. return은 정리된 sorted_SLL의 head.
"""
"""constraint :
노드 개수는 0~300
-100 <= Node.val <= 100
SLL은 ascending order로 sort되어있어야 함.
"""

"""문제풀이
    1. two pointer 처럼 풀면된다. 
        prev : 각 숫자별 맨 처음에 나온 노드에 머무름.
        cur : 모든 노드를 순회하는 역할.
    2. cur != None일 동안 반복. 
        if prev.val == cur.val :
            cur = cur.next
        else :
            prev.next = cur (이런 식으로 풀이하려면, 1. prev, cur 시작 부분 & 2. while문 탈출 후 prev.next에 대한 처리 필요.)
            prev = cur
            cur = cur.next
    3. return head
    4. edges 
        비어있는 list
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    #풀이 1
    def deleteDuplicates(self, head):
        if head == None:
            return head
        
        prev = head
        cur = head
        
        while cur != None:
            if prev.val == cur.val :  #여기 조건만 바꾸면 일반적인 remove로 사용할 수 있겠다.
                cur = cur.next
                prev.next = cur
            else :
                prev = cur
                cur = cur.next
        return head

    #풀이 2
    def deleteDuplicates(self, head):
        if head is None:
            return head
        
        prev = head
        cur = head.next  # cur를 head.next에서 시작
        
        while cur is not None:
            if prev.val == cur.val:
                cur = cur.next  # 중복 발견 시 cur만 다음으로 이동
            else:
                prev.next = cur  # 중복이 끝난 지점에서 prev.next 업데이트
                prev = cur
                cur = cur.next
        
        prev.next = None  # 리스트 끝에서 중복을 제거하기 위해 추가 (이 코드가 없을 때는, SLL 마지막에 중복 노드들이 있을 때 처리하지 못함. cur이 None이 되었을 때 prev.next를 update하지 못하기 때문.)
        return head