class MinStack:
    # stack that supports push, pop, top, and retrieving the minimum element in constant time
    # ref. https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
    # LIFO (Last-In-First-Out)

    def __init__(self):
        # initialize two stacks
        self.main_stack = [] # 1. store all values
        self.min_stack = [] # 2. store minimum values

    def push(self, val: int) -> None:
        # push value onto main stack
        self.main_stack.append(val)
        # min stack is empty or value is new minimum
        if (not self.min_stack) or (val <= self.min_stack[-1]):
            self.min_stack.append(val) # push value onto min stack as well

    def pop(self) -> None:
        # remove top element from main stack
        if self.main_stack:
            # top of main stack is current minimum
            if self.main_stack[-1] == self.min_stack[-1]:
                self.min_stack.pop() # remove from min stack as well
            self.main_stack.pop()

    def top(self) -> int:
        # Return the top element of the main stack
        if self.main_stack:
            return self.main_stack[-1]

    def getMin(self) -> int:
        # Return the top element of the min stack (the current minimum)
        if self.min_stack:
            return self.min_stack[-1]
        

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

# Example usage
# Your MinStack object will be instantiated and called as such:
obj = MinStack()
obj.push(-2)
obj.push(0)
obj.push(-3)
print(obj.getMin())  # Output: -3
obj.pop()
print(obj.top())     # Output: 0
print(obj.getMin())  # Output: -2

"""
0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week08 (main)
$ python minstack.py
-3
0
-2
"""