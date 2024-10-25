class MinStack(object):

    def __init__(self):
        self.top_idx = -1
        self.stack = []
        

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.stack.append(val)
        self.top_idx += 1
        

    def pop(self):
        """
        :rtype: None
        """
        if self.top_idx != -1:
            del self.stack[self.top_idx]
            self.top_idx -= 1
        

    def top(self):
        """
        :rtype: int
        """
        if self.top_idx != -1:
            return self.stack[self.top_idx]
        

    def getMin(self):
        """
        :rtype: int
        """
        if self.top_idx != -1:
            return min(self.stack)
        

minStack = MinStack()
minStack.push(-2)
minStack.push(0)
minStack.push(-3)
print(minStack.getMin())   # -3
minStack.pop()
print(minStack.top())
print(minStack.getMin())
 