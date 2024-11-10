"""문제
2개의 sorted SLL이 있을 때, 이것들을 하나의 sorted SLL로 변환.(non-decreasing order)
return the head of the merged linked list.
"""

"""Constraint
    노드 개수 0~50
    -100 <= node.val <= 100
"""

"""문제풀이1
    1. 새로운 List의 시작점을 dummy_head로 만든다. (그러면 나중에 return이 쉬움. dummy_head->next)
    2. List1, List2 각각에 대해 temp1, temp2를 한칸씩 이동하면서 요소를 차례로 가져온다.
    3. temp1, temp2에 해당하는 노드를 추출할 때 조건 : temp1 <= temp2 이면 temp1, 반대면 temp2
    4. 2,3과정은 temp1, temp2가 모두 None이 아닌동안 반복. temp1 != None and temp2 !=None
    5. temp1, temp2 중 하나만 None에 도달하고 끝났을때 처리. 여전히 다른 하나가 None에 도달못했다면, 도달못한 temp를 뒤에 이어주어야 함.
"""

"""문제풀이2 : Recursive (작은 노드를 merged된 노드의 끝에 붙이는 것.)
    1.
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
#문제풀이 1
    def mergeTwoLists(self, list1, list2):
        dummy_head = ListNode(-200)
        
        temp1 = list1
        temp2 = list2
        new_cur = dummy_head;
        
        while temp1 != None and temp2 != None:
            if temp1.val <= temp2.val :
                new_cur.next = temp1
                temp1 = temp1.next
                new_cur = new_cur.next
            else :
                new_cur.next = temp2
                temp2 = temp2.next
                new_cur = new_cur.next
    # 5.
        if temp1 == None:
            new_cur.next = temp2

        if temp2 == None:
            new_cur.next = temp1
            
    #5.다른방법(또는 아래와 같이 써도 됨.)
        # if temp1 != None:
        #     new_cur.next = temp1

        # if temp2 != None:
        #     new_cur.next = temp2
                
        return dummy_head.next

#문제풀이2
    def mergeTwoLists(self, list1, list2):
        if list1 == None:
            return list2
        if list2 == None:
            return list1
        
        if list1.val <= list2.val :
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list2.next, list1)
            return list2
