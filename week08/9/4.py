class MinStack:

    def __init__(self):
        self.stack = []  # Main stack to store all elements
        self.min_stack = []  # Auxiliary stack to store the minimum element at each point

    def push(self, val: int) -> None:
        # Push the value onto the main stack
        self.stack.append(val)
        
        # Push the current minimum value onto the min stack
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self) -> None:
        # Pop the top value from the main stack
        if self.stack:
            popped = self.stack.pop()
            # If the popped value is the current minimum, pop it from the min stack as well
            if popped == self.min_stack[-1]:
                self.min_stack.pop()

    def top(self) -> int:
        # Return the top element of the main stack
        if self.stack:
            return self.stack[-1]
        return -1  # If the stack is empty

    def getMin(self) -> int:
        # Return the minimum element from the min stack
        if self.min_stack:
            return self.min_stack[-1]
        return -1  # If the stack is empty
