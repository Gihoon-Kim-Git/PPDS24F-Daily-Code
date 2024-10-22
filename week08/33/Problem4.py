# stack 구현 
# 조건) push, pop, top, getMin을 O(1)에 수행

class MinStack:

    def __init__(self):
        self.stack = []
        self.topIndex = -1
        self.min = None
        

    def push(self, val: int) -> None:
        self.stack.append(val)
        self.topIndex += 1
        if self.min is None or self.min > val:
            self.min = val
        
    def pop(self) -> None:
        val = self.stack.pop()
        self.topIndex -= 1
        if val == self.min:
            if self.stack:
                self.min = min(self.stack)
            else:
                self.min = None

    def top(self) -> int:
        return self.stack[self.topIndex]
        

    def getMin(self) -> int:
        print(self.min)
        return self.min
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()