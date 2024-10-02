"""문제 : 어떤 Singlyl linked list의 head가 주어졌을 때, SLL에서 특정 val값 가지는 node를 모두 제거&& return new head"""

"""문제풀이1
    1. head부터 마지막 노드까지 순회(prev, cur 유지)하면서 cur.val == val인 경우 remove 처리
        - 마지막 처리 조건 : cur == None 이 되면 while문 탈출
    2. remove 처리 : prev와 cur.next를 연결. (prev.next == cur.next 하고 cur = cur.next)로. (else : prev, cur 한꺼번에 update)
    3. edge case : head == None
    4. new_head 반환. head.val != val일때까지 찾아서 그 때의 head 반환.
"""

"""문제풀이2
    1. 그냥 새로 SLL을 만들자. head부터 마지막 노드까지 순회하면서  cur.val != target_val인 경우에만 노드 만들어서 추가.
"""

"""문제풀이3 : Dummy node를 활용하는 방법
    1. 현재 head 전에 dummy node를 하나 만들어줌. dummy.next = head
    2. dummy_head부터 시작해서 cur.next.val == val 조건 확인 및 remove 진행 (cur.next.val==val이면, cur.next를 cur.next.next로 바꿔주기.)
    3. 반환은 dummy.next를 하면 됨.

"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def list_to_SLL(head_list) -> ListNode :
    #list가 비어있으면 None 반환
    if not head_list : 
        return None
    #첫번째 노드 생성하여 head로
    head = ListNode(head_list[0])
    cur = head
    #나머지 list 요소 순회하면서 SLL로 변환
    for elem in head_list[1:]:
        cur.next = ListNode(elem)
        cur = cur.next
    
    return head
    
def SLL_to_list(head : ListNode) -> list:
    my_list = []
    cur = head

    #head가 None이면 비어있는 list인 [] 반환
    if cur == None :
        return my_list
    
    while cur!= None:
        my_list.append(cur.val)
        cur = cur.next
    return my_list

class Solution:
    #return new_head
    #풀이1
    def removeElements(self, head, target_val: int) :  
        if head == None:
            return head
        
        prev = head
        cur = head
        
        while cur != None:
            if cur.val == target_val :
                prev.next = cur.next
                cur = cur.next  # 이 경우에는 prev를 업데이트 하지 않아야함. 그래야 target_val이 연속해서 있더라도 문제없이 처리가능.
            else :
                prev = cur
                cur = cur.next
        
        #new head를 찾는 과정.
        while head and head.val == target_val :
            head = head.next
        return head
    
    #풀이 2 : 통과
    def removeElements(self, head, target_val):
        if head == None:
            return head

        new_cur = None
        new_head = None
        cur = head
        while cur != None:
            if cur.val != target_val :
                new_Node = ListNode(cur.val)
                #new SLL에 요소가 하나도 없는 경우. new_head가 만들어짐
                if new_cur == None:
                    new_cur = new_Node
                    new_head = new_Node
                #new SLL에 요소가 하나라도 있는 경우. head는 이미 있으므로 신경쓰지 않아도 됨.
                else :
                    new_cur.next = new_Node
                    new_cur = new_cur.next
            cur = cur.next
            
        return new_head
    
    #풀이 3 : 
    def removeElements(self, head, target_val):
        dummy_head = ListNode(-1)
        dummy_head.next = head
        
        cur = dummy_head
        while cur.next != None:
            if cur.next.val == target_val :
                cur.next = cur.next.next
            else:
                cur = cur.next
        return dummy_head.next

if __name__ == "__main__":
    #Test1
    head_list = [1,2,6,3,4,5,6]
    val = 6
    expected_result = [1,2,3,4,5]
    head = list_to_SLL(head_list)
    sol = Solution()
    my_new_head = sol.removeElements(head, val)
    my_result = SLL_to_list(my_new_head)
    print("Test1 Passed") if expected_result == my_result else print("Test1 Failed")
    
    #Test2
    head_list = []
    val = 1
    expected_result = []
    head = list_to_SLL(head_list)
    sol = Solution()
    my_new_head = sol.removeElements(head, val)
    my_result = SLL_to_list(my_new_head)
    print("Test2 Passed") if expected_result == my_result else print("Test2 Failed")

    #Test3
    head_list = [7,7,7,7]
    val = 7
    expected_result = []
    head = list_to_SLL(head_list)
    sol = Solution()
    my_new_head = sol.removeElements(head, val)
    my_result = SLL_to_list(my_new_head)
    print("Test3 Passed") if expected_result == my_result else print("Test3 Failed")