from collections import deque

class MyStack:
    def __init__(self):
        self.queue1 = deque()  # Main queue
        self.queue2 = deque()  # Auxiliary queue

    def push(self, x: int) -> None:
        self.queue1.append(x)

    def pop(self) -> int:
        # Move all elements except the last to queue2
        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())
        # Last element of queue1 is the top of the stack
        top_element = self.queue1.popleft()
        # Swap queue1 and queue2
        self.queue1, self.queue2 = self.queue2, self.queue1
        return top_element

    def top(self) -> int:
        # Move all elements except the last to queue2
        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())
        # Last element of queue1 is the top of the stack
        top_element = self.queue1.popleft()
        self.queue2.append(top_element)  # Put it back into queue2
        # Swap queue1 and queue2
        self.queue1, self.queue2 = self.queue2, self.queue1
        return top_element

    def empty(self) -> bool:
        return not self.queue1

# Example usage
stack = MyStack()
stack.push(1)
stack.push(2)
print(stack.top())   # Output: 2
print(stack.pop())   # Output: 2
print(stack.empty()) # Output: False
