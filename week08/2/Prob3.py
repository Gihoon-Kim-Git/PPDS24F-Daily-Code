class MyCircularDeque:

    def __init__(self, k: int):
        self.k = k
        self.deque = [0] * k
        self.front = 0
        self.rear = 0
        self.size = 0

    def insertFront(self, value: int) -> bool:
        # if deque is full, return False
        if self.isFull():
            return False
        # 현재 기준 deque의 맨 앞보다 한칸 앞의 값을 circular하게 찾기 위해 modulo 연산 수행
        # 가득 차 있지 않기 때문에 front보다 한칸 앞은 비어 있음
        self.front = (self.front - 1) % self.k
        self.deque[self.front] = value
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        # if deque is full, return False
        if self.isFull():
            return False
        self.deque[self.rear] = value
        # 현재 기준 deque의 맨 끝보다 한칸 뒤의 값을 circular하게 찾아 re-assign
        self.rear = (self.rear + 1) % self.k
        self.size += 1
        return True
        

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % self.k
        self.size -= 1
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        self.rear = (self.rear - 1) % self.k
        self.size -= 1
        return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.deque[self.front]

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.deque[(self.rear - 1 ) % self.k]
        

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.k


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