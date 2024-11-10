#Min Stack
class MinStack:
    def __init__(self):
        # Initialize two stacks: one for regular elements and one for maintaining the minimum at each step.
        self.stack = []
        self.minStack = []

    def push(self, val: int) -> None:
        # Push the value onto the regular stack.
        self.stack.append(val)
        # Update the value to be pushed onto the minimum stack, considering the current minimum.
        val = min(val, self.minStack[-1] if self.minStack else val)
        # Push the updated value onto the minimum stack.
        self.minStack.append(val)

    def pop(self) -> None:
        # Pop elements from both stacks to maintain synchronization.
        self.stack.pop()
        self.minStack.pop()

    def top(self) -> int:
        # Retrieve the top element from the regular stack.
        return self.stack[-1]

    def getMin(self) -> int:
        # Retrieve the top element from the minimum stack, representing the current minimum.
        return self.minStack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()