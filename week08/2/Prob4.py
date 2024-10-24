class MinStack:

    def __init__(self):
        self.minval = []
        self.stack = []


    def push(self, val: int) -> None:
        self.stack.insert(0, val)
        if len(self.minval) == 0:
            self.minval.insert(0, val)
        else:
            if self.minval[0] >= val:
                self.minval.insert(0, val)

    def pop(self) -> None:
        temp = self.stack.pop(0)
        if self.minval[0] == temp:
            self.minval.pop(0)

    def top(self) -> int:
        
        if len(self.stack) == 0:
            return False
        
        return self.stack[0]

    def getMin(self) -> int:
        
        if len(self.stack) == 0:
            return False
        
        return self.minval[0]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()