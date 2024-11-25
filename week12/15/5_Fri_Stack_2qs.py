class MyStack:

    def __init__(self):
        self.queue1 = []
        self.queue2 = []

    def push(self, x: int) -> None:
        if self.queue1:
            while self.queue1:
                dat = self.queue1.pop(0)
                self.queue2.append(dat)
            self.queue1.append(x)
            while self.queue2:
                dat = self.queue2.pop(0)
                self.queue1.append(dat)
        else:
            self.queue1.append(x)

    def pop(self) -> int:
        return self.queue1.pop(0)

    def top(self) -> int:
        return self.queue1[0]  

    def empty(self) -> bool:
        return len(self.queue1) == 0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()