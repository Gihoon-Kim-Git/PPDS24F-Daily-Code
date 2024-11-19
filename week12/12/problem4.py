class MyQueue:

    def __init__(self):
        self.q= []
        

    def push(self, x: int) -> None:
        self.q.append(x)

    def pop(self) -> int:
        ans= self.q[0]
        self.q.pop(0)
        return ans

    def peek(self) -> int:
        return self.q[0]

    def empty(self) -> bool:
        return len(self.q)==0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()