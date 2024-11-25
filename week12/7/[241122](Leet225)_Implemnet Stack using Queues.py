"""Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations."""

"""아이디어
    Stack안에 store_Queue, temp_queue을 만든다.
    push할 때 store_queue에 있는 요소들을 모든 요소를 temp_queue으로 옮기고 temp_queue를 store_queue로 바꿔주면 됨!
    근데 시간을 아끼려면 temp_queue이 비어있을 때만 store-queue에서 옮기는 작업을 하면 됨.
"""
"""Develeoped Amswer(하나의 queue만 사용) : 
    deqeue에 넣고, 맨 앞의 요소( 먼저 들어와 있는 것)를 제외하고 나머지는 뺐다가 다시 넣음."""

## 두 개의 qeuue 사용
from collections import deque

class MyStack:
    def __init__(self):
        self.store_q = deque()
        self.temp_q = deque()
        
    def push(self, x: int) -> None:
        self.store_q.append(x)
        
    def pop(self) -> int:
        n = len(self.store_q)
        for _ in range(n-1):
            x = self.store_q.popleft()
            self.temp_q.append(x)
        
        popped_element = self.store_q.popleft()
        
        #swap q1 and q2    
        self.store_q, self.temp_q = self.temp_q, self.store_q
        
        return popped_element

    def top(self) -> int:
        n = len(self.store_q)
        for _ in range(n-1):
            x = self.store_q.popleft()
            self.temp_q.append(x)
        
        top_element = self.store_q[0]
        self.store_q.popleft()
        
        self.temp_q.append(top_element)
        
        #swap q1 and q2    
        self.store_q, self.temp_q = self.temp_q, self.store_q
        
        return top_element
        
    def empty(self) -> bool: # store_q에 요소가 있으면 false, 요소가 없으면 true
        return False if self.store_q else True






##---- 하나의 queue만 사용
from collections import deque

class MyStack:
    def __init__(self):
        self.store_q = deque()
        
    def push(self, x: int) -> None:
        self.store_q.append(x)
        n = len(self.store_q)
        for _ in range(n-1):
            x = self.store_q.popleft()
            self.store_q.append(x)

    def pop(self) -> int:  
        return self.store_q.popleft()

    def top(self) -> int:        
        return self.store_q[0]
        
    def empty(self) -> bool: # store_q에 요소가 있으면 false, 요소가 없으면 true
        return False if self.store_q else True
        
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()