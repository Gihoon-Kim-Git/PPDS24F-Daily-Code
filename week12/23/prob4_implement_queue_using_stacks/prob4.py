class MyQueue:
    def __init__(self):
        self.stack1 = []  # Used for push operations
        self.stack2 = []  # Used for pop/peek operations

    def push(self, x: int) -> None:
        self.stack1.append(x)

    def pop(self) -> int:
        self._move()
        return self.stack2.pop()

    def peek(self) -> int:
        self._move()
        return self.stack2[-1]

    def empty(self) -> bool:
        return not self.stack1 and not self.stack2

    def _move(self):
        if not self.stack2:  # Only move elements if stack2 is empty
            while self.stack1:
                self.stack2.append(self.stack1.pop())

# Example usage
queue = MyQueue()
queue.push(1)
queue.push(2)
print(queue.peek())  # Output: 1
print(queue.pop())   # Output: 1
print(queue.empty()) # Output: False
