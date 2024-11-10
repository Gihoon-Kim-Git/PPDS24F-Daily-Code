class MyCircularDeque:

    def __init__(self, k: int):
        self.capacity = k
        self.size = 0
        self.mydq = [-1] * k
        self.front = 0
        self.last = 0

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        if self.isEmpty():
            self.mydq[self.front] = value 
        else:
            self.front = (self.front - 1) % self.capacity
            self.mydq[self.front] = value 
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        if self.isEmpty():
            self.mydq[self.last] = value
        else:
            self.last = (self.last + 1) % self.capacity
            self.mydq[self.last] = value
        self.size += 1
        return True                

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        else:
            self.mydq[self.front] = -1
            self.front = (self.front + 1) % self.capacity
            self.size -= 1
            if self.isEmpty():
                self.last = self.front
            return True
        
    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        else:
            self.mydq[self.last] = -1
            self.last = (self.last - 1) % self.capacity
            self.size -= 1
            if self.isEmpty():
                self.front = self.last
            return True
        
    def getFront(self) -> int:
        return self.mydq[self.front]

    def getRear(self) -> int:
        return self.mydq[self.last]    

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.capacity


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