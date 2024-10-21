class MinStack:

    def __init__(self):
        self.mp = []  

    def push(self, val: int) -> None:
        if not self.mp:
            self.mp.append((val, val))
        else:
            minval = self.mp[-1][1]
            self.mp.append((val, min(minval, val)))

    def pop(self) -> None:
        if self.mp:
            self.mp.pop() 

    def top(self) -> int:
        
        return self.mp[-1][0]  

    def getMin(self) -> int:
        
        return self.mp[-1][1]  

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()