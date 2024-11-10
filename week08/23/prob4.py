class MinStack:

    def __init__(self):
        self.stack = []  # The main stack to store values
        self.min_stack = []  # A stack to keep track of the minimum values

    def push(self, val: int) -> None:
        self.stack.append(val)
        # If the min_stack is empty or the current value is smaller or equal to the top of min_stack, push it to the min_stack
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self) -> None:
        # Pop from the main stack
        if self.stack:
            val = self.stack.pop()
            # If the popped value is equal to the top of the min_stack, pop it from min_stack as well
            if self.min_stack and val == self.min_stack[-1]:
                self.min_stack.pop()

    def top(self) -> int:
        # Return the top element of the main stack
        if self.stack:
            return self.stack[-1]

    def getMin(self) -> int:
        # Return the top element of the min_stack, which holds the minimum value
        if self.min_stack:
            return self.min_stack[-1]

# Your MinStack object will be instantiated and called as such:
obj = MinStack()
obj.push(-2)
obj.push(0)
obj.push(-3)
print(obj.getMin())  
obj.pop()
print(obj.top())     
print(obj.getMin()) 
