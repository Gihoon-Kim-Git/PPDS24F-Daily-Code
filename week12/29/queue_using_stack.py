"""
<Implement Queue using Stacks>
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
"""

class MyQueue:
    def __init__(self):
        # Two stacks: one for pushing elements, one for popping
        self.stack_in = []
        self.stack_out = []

    def push(self, x: int) -> None:
        self.stack_in.append(x)

    def pop(self) -> int:
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())
        return self.stack_out.pop()

    def peek(self) -> int:
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())
        return self.stack_out[-1]

    def empty(self) -> bool:
        return not self.stack_in and not self.stack_out

queue = MyQueue()
queue.push(1)
queue.push(2)
print(queue.peek())  # 1
print(queue.pop())   # 1
print(queue.empty()) # False
