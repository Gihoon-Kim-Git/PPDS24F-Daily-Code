class MyQueue:

    def __init__(self):
        self.stack1 = []
        self.stack2 = []
        self.size = 0

    def push(self, x: int) -> None:
        if self.stack1:
            while self.stack1:
                dat = self.stack1.pop()          
                self.stack2.append(dat)            
            self.stack1.append(x)

            while self.stack2:
                dat = self.stack2.pop()
                self.stack1.append(dat)
        else:
            self.stack1.append(x)
        self.size += 1

    def pop(self) -> int:
        if self.stack1:            
            self.size -= 1
            return self.stack1.pop()

    def peek(self) -> int:
        return self.stack1[-1]

    def empty(self) -> bool:
        if self.size == 0:
            return True
        else:
            return False
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()