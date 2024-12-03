class MyQueue:

    def __init__(self):
        self.stack_in = []  # Stack for push operations
        self.stack_out = []  # Stack for pop/peek operations

    def push(self, x: int) -> None:
        self.stack_in.append(x)

    def pop(self) -> int:
        self._move()
        return self.stack_out.pop()

    def peek(self) -> int:
        self._move()
        return self.stack_out[-1]

    def empty(self) -> bool:
        return not self.stack_in and not self.stack_out

    def _move(self):
        # Transfer elements from stack_in to stack_out if stack_out is empty
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())
