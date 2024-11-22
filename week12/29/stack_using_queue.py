"""
<Implement Stack using Queues>

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
"""

from collections import deque

class MyStack:
    def __init__(self):
        # Two queues: one for the main stack, one as a temporary buffer
        self.queue1 = deque()
        self.queue2 = deque()

    def push(self, x: int) -> None:
        self.queue1.append(x)

    def pop(self) -> int:
        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())
        top_element = self.queue1.popleft()
        self.queue1, self.queue2 = self.queue2, self.queue1
        return top_element

    def top(self) -> int:
        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())
        top_element = self.queue1.popleft()
        self.queue2.append(top_element)  # Put the element back into queue2
        self.queue1, self.queue2 = self.queue2, self.queue1
        return top_element

    def empty(self) -> bool:
        return not self.queue1

stack = MyStack()
stack.push(1)
stack.push(2)
print(stack.top())   # 2
print(stack.pop())   # 2
print(stack.empty()) # False

        
