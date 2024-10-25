class MyCircularDeque:

    def __init__(self, k: int):
        self.deque = []
        self.max_len = k
        
    def insertFront(self, value: int) -> bool:
        if len(self.deque) + 1 <= self.max_len:
            self.deque = [value] + self.deque
            return True
        return False

    def insertLast(self, value: int) -> bool:
        if len(self.deque) + 1 <= self.max_len:
            self.deque =  self.deque + [value]
            return True
        return False

    def deleteFront(self) -> bool:
        try:
            self.deque.pop(0)
            return True
        except:
            return False

        

    def deleteLast(self) -> bool:
        try:
            self.deque.pop()
            return True
        except:
            return False
        

    def getFront(self) -> int:
        try:
            return self.deque[0]
        except:
            return -1
        

    def getRear(self) -> int:
        try:
            return self.deque[-1]
        except:
            return -1
        

    def isEmpty(self) -> bool:
        return len(self.deque) == 0
        

    def isFull(self) -> bool:
        return len(self.deque) == self.max_len
        


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()