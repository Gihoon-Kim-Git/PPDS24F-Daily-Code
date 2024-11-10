class MinStack:

    def __init__(self):
        self.mainstack = []
        self.minstack = []

    def push(self, val: int) -> None:
        self.mainstack.append(val)
        
        if not self.minstack or val <= self.minstack[-1]:
            self.minstack.append(val)

    def pop(self) -> None:
        if self.mainstack:
            if self.mainstack[-1] == self.minstack[-1]:
                self.minstack.pop()
            self.mainstack.pop()        

    def top(self) -> int:
        if self.mainstack:
            return self.mainstack[-1]

    def getMin(self) -> int:
        if self.minstack:
            return self.minstack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()