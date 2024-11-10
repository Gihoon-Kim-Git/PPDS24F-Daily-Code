class MyCircularDeque:
    def __init__(self, k: int):
        self.capa = k
        self.size = 0
        self.deque = []

    def insertFront(self, value: int) -> bool:
        if self.isFull() :return False
        else:
            if self.deque != []:
                self.deque.insert(0,value)
                self.size+=1
            else :
                self.deque.append(value)
                self.size+=1            
        return True
    def insertLast(self, value:int) -> bool:
        if self.isFull() :return False
        self.deque.append(value)
        self.size+=1
        return True
    def deleteFront(self) -> bool:
        if self.isEmpty():return False
        self.deque.pop(0)
        self.size-=1
        return True
    def deleteLast(self) -> bool:
        if self.isEmpty():return False
        self.deque.pop()
        self.size-=1
        return True
    def getFront(self) -> int:
        if self.isEmpty():return -1
        return self.deque[0]

    def getRear(self) -> int:
        if self.isEmpty():return -1
        return self.deque[self.size-1]

    def isEmpty(self) -> bool:
        return self.size == 0
    def isFull(self) -> bool:
        return self.size == self.capa
        


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