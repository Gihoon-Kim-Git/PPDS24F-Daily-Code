from queue import Queue

class MyStack:

    def __init__(self):
        self.main = Queue()
        self.sub = Queue()

    def push(self, x: int) -> None:
        self.main.put(x)

    def pop(self) -> int:
        if self.main.empty():
            return

        while self.main.qsize() != 1:  # 메인 큐가 1개 남을 때까지 임시 큐에 넣기
            self.sub.put(self.main.get())

        result = self.main.get()

        self.main, self.sub = self.sub, self.main  # swap
        return result

    def top(self) -> int:
        while self.main.qsize() > 1:
            self.sub.put(self.main.get())

        # Get the last element, which is the top of the stack
        result = self.main.get()

        # Push the top element back into the sub queue
        self.sub.put(result)

        # Swap main and sub queues
        self.main, self.sub = self.sub, self.main
        return result
    
    
    def empty(self) -> bool:
        return self.main.empty()


