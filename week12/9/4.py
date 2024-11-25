class MyQueue:

    def __init__(self):
        self.inbox = list()
        self.outbox = list()
        
    def push(self, x: int) -> None:
        self.inbox.append(x)        

    def pop(self) -> int:
        if not self.outbox:
            while self.inbox:
                self.outbox.append(self.inbox.pop())
        return self.outbox.pop()


    def peek(self) -> int:
        if not self.outbox:
            while self.inbox:
                self.outbox.append(self.inbox.pop())
        return self.outbox[-1]  # Peek the front element from the outbox

    def empty(self) -> bool:
        return len(self.inbox) == 0 and len(self.outbox) == 0
