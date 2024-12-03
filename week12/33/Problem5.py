from collections import deque

class MyStack:
    def __init__(self):
        self.queue1 = deque()
        self.queue2 = deque()

    def push(self, x: int) -> None:
        # Push x into queue2
        self.queue2.append(x)
        # Transfer all elements from queue1 to queue2
        while self.queue1:
            self.queue2.append(self.queue1.popleft())
        # Swap queue1 and queue2
        self.queue1, self.queue2 = self.queue2, self.queue1

    def pop(self) -> int:
        # Remove and return the front element of queue1
        return self.queue1.popleft()

    def top(self) -> int:
        # Return the front element of queue1
        return self.queue1[0]

    def empty(self) -> bool:
        # Check if queue1 is empty
        return not self.queue1
