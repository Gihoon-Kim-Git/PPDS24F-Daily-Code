"""Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.

Notes:
    You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

Constraints:
    1 <= x <= 9
    At most 100 calls will be made to push, pop, peek, and empty.
    All the calls to pop and peek are valid.
"""
#하나의 stack만 사용해서 Queue를 구현하는 방법

class MyQueue:
    def __init__(self):
        self.stack1 = []
    
    def push(self, x):
        temp = []
        while self.stack1 :
            y = self.stack1.pop()
            temp.append(y)
        #이전에 있던 거를 다 옮겨주고 그다음에 이번에 넣는 요소를 넣고, 그다음에 다시 옮기기.    
        self.stack1.append(x)
        while temp:
            y = temp.pop()
            self.stack1.append(y)
    
    def pop(self):
        front = self.stack1[-1]
        self.stack1.pop()
        return front

    def peek(self):
        return self.stack1[-1]
    
    def empty(self):
        return not self.stack1

#%%
"""아이디어
    값을 보관하는 stack 하나(store_stack)
    만약 peek, pop을 해야한다면, store_stack에서 하나씩 요소를 빼서 temp_stack으로 전부 다 옮긴다. 이후 pop, peek을 하면 됨. 
    temp_stack이 비기 전까지는 temp_stack에서 뽑기만 하면 되고, 만약 temp_stack이 비어버린다면, 다시 store_stack에서 값을 가져와야함.
"""

"""수도코드
목표 : stack 2개를 사용해서 class MyQueue()를 구현한다.

1. __init__():
    store_stack = stack()
    temp_stack = stack()
    
2. push(x):
    store_stack.push(x)

3. pop():

    만약 temp_stack이 비어있다면, 요소 옮기기 진행
        while store_stack에 요소가 존재하는 동안
            x = store_stack.pop()
            temp_stack.push(x)
    
    temp_stack이 비어있지 않다면, 그냥 temp_stack에서 pop을 하기만 하면 된다.
    return temp_stack.pop()
    
4. peek():
    만약 temp_stack이 비어있다면, 요소 옮기기 진행
        while store_stack에 요소가 존재하는 동안
            x = store_stack.pop()
            temp_stack.push(x)
    
    temp_stack이 비어있지 않다면, 그냥 temp_stack에서 peek을 하기만 하면 된다.
    return temp_stack.peek()

5. empty():
    return temp_stack이랑 store_stack이 모두 비어있어야 empty이다.
"""

#%% Trial3 : 통과!!
class stack:
    def __init__(self):  # 스택 객체 생성
        self.items = []

    def push(self, item):  # 스택 요소 추가 push(.append())
        self.items.append(item)

    def pop(self):  # 스택 맨 뒤 요소 삭제하고 리턴 pop()
        return self.items.pop()

    def peek(self):  # 스택 맨 뒤 요소 리턴
        return self.items[-1]

    def isEmpty(self):  # 스택이 비었는지 확인(비었으면 True 리턴)
        return not self.items


class MyQueue(object):

    def __init__(self):
        self.store_stack = stack()
        self.temp_stack = stack()

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.store_stack.push(x)

    def pop(self):
        """
        :rtype: int
        """
        if self.temp_stack.isEmpty(): 
            while not self.store_stack.isEmpty():
                x = self.store_stack.pop()
                self.temp_stack.push(x)
        
        return  self.temp_stack.pop() 

    def peek(self):
        """
        :rtype: int
        """
        if self.temp_stack.isEmpty(): 
            while not self.store_stack.isEmpty():
                x = self.store_stack.pop()
                self.temp_stack.push(x)
        
        return  self.temp_stack.peek() 

            

    def empty(self):
        """
        :rtype: bool
        """
        is_store_empty = True if self.store_stack.isEmpty() else False
        is_temp_empty = True if self.temp_stack.isEmpty() else False
        
        return is_store_empty and is_temp_empty

    
        #        return not self.store_stack and not self.temp_stack  ## 처음에 이거 넣었을 때 틀림! (False and False이면 False가 되는게 문제.)


#%% Trial 2 : Trial1과 동일한데 deque로 구현 (Time Limit exceeded)
from collections import deque

class MyQueue(object):

    def __init__(self):
        self.store_stack = deque()
        self.temp_stack = deque()

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.store_stack.append(x)

    def pop(self):
        """
        :rtype: int
        """
        while len(self.store_stack) != 0:
            self.temp_stack.append(self.store_stack.pop())
        
        answer = self.temp_stack.pop()
        
        while len(self.temp_stack) != 0:
            self.store_stack.append(self.temp_stack.pop())
    
        return answer
        

    def peek(self):
        """
        :rtype: int
        """
        while len(self.store_stack) != 0:
            x = self.store_stack[-1]
            self.temp_stack.append(x)

        return self.temp_stack.pop() if self.temp_stack else print("no top")
            

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.store_stack) == 0
    
obj = MyQueue()
obj.push(3)
param_2 = obj.pop()
param_3 = obj.peek()
param_4 = obj.empty()

print(param_2, param_3, param_4)





#%% 
## Trial 1 : Time Limit Exceeded

class stack:
    def __init__(self):  # 스택 객체 생성
        self.items = []

    def push(self, item):  # 스택 요소 추가 push(.append())
        self.items.append(item)

    def pop(self):  # 스택 맨 뒤 요소 삭제하고 리턴 pop()
        return self.items.pop()

    def peek(self):  # 스택 맨 뒤 요소 리턴
        return self.items[-1]

    def isEmpty(self):  # 스택이 비었는지 확인(비었으면 True 리턴)
        return not self.items


class MyQueue(object):

    def __init__(self):
        self.store_stack = stack()
        self.temp_stack = stack()

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.store_stack.push(x)

    def pop(self):
        """
        :rtype: int
        """
        while not self.store_stack.isEmpty():
            x = self.store_stack.pop()
            self.temp_stack.push(x)
        
        answer = self.temp_stack.pop()
        
        while not self.temp_stack.isEmpty():
            r = self.temp_stack.pop()
            self.store_stack.push(r)
    
        return answer
        

    def peek(self):
        """
        :rtype: int
        """
        while not self.store_stack.isEmpty():
            x = self.store_stack.peek()
            self.temp_stack.push(x)
        
        if self.temp_stack :
            return self.temp_stack.pop()
            

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.store_stack) == 0





#%%
##-------------[Stack class 정의]

#기본
class stack:
    def __init__(self):  # 스택 객체 생성
        self.items = []

    def push(self, item):  # 스택 요소 추가 push(.append())
        self.items.append(item)

    def pop(self):  # 스택 맨 뒤 요소 삭제하고 리턴 pop()
        return self.items.pop()

    def peek(self):  # 스택 맨 뒤 요소 리턴
        return self.items[-1]

    def isEmpty(self):  # 스택이 비었는지 확인(비었으면 True 리턴)
        return not self.items

#함수 추가
class Stack2:
    #리스트를 이용하여 스택 생성
    def __init__(self, limit: int= 100):
        self.top = []
        self.limit = limit
    #스택 크기 반환
    def __len__(self) -> bool :
        return len(self.top)
    #스택 내부 자료 전체를 string으로 변환하여 반환
    def __str__(self) -> str :
        return str(self.top[::1])

    #구현함수
    #스택에 원소 삽입
    def push(self, item):
        if(len(self.pop)>=self.limit):
            self.top.append(item)
    #스택 가장 위에 있는 원소를 삭제하고 반환
    def pop(self):
        if not self.isEmpty():
            return self.top.pop(-1)
        else:
            print("Stack underflow")
            exit()
    #스택 가장 위에 있는 원소를 반환
    def peek(self):
        if not self.isEmpty():
            return self.top[-1]
        else:
            print("underflow")
            exit()
    #스택을 비움
    def clear(self):
        self.top=[]
    #스택 안에 특정 item이 포함되어 있는지를 bool값으로 반환
    def isContain(self, item) -> bool:
        return item in self.top
    #스택이 비어있는 지를 bool값으로 반환
    def isEmpty(self) -> bool :
        return len(self.top)==0
    #스택이 가득 차 있는 지를 bool값으로 반환
    def isFull(self) -> bool :
        return self.size()==self.limit
    #스택의 크기를 int 값으로 반환 
    def size(self) -> int :
        return len(self.top)



# %%
