# deque 구현
"""
내 코드
run time이 나쁘지는 않지만 circular queue로 구현한 것은 아님
"""
class MyCircularDeque:

    def __init__(self, k: int):
        self.deque = []
        self.size = 0
        self.capacity = k

    def insertFront(self, value: int) -> bool:
        if self.size < self.capacity:
            self.deque.insert(0, value)
            self.size += 1
            return True
        else:
            return False

    def insertLast(self, value: int) -> bool:
        if self.size < self.capacity:
            self.deque.append(value)
            self.size += 1
            return True
        else:
            return False

    def deleteFront(self) -> bool:
        if self.size > 0:
            self.deque.pop(0)
            self.size -= 1
            return True
        else:
            return False

    def deleteLast(self) -> bool:
        if self.size > 0:
            self.deque.pop()
            self.size -= 1
            return True
        else:
            return False
    def getFront(self) -> int:
        if self.size > 0:
            return self.deque[0]
        else:
            return -1

    def getRear(self) -> int:
        if self.size > 0:
            return self.deque[self.size-1]
        else:
            return -1

    def isEmpty(self) -> bool:
        if self.size > 0:
            return False
        else:
            return True

    def isFull(self) -> bool:
        if self.size == self.capacity:
            return True
        else:
            return False
        


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


"""
GPT 코드 - circular queue 구현
(circular 아니게 푼 거랑 run time 크게 차이 안남)

!!!
python에서 fixed size array 만들 때 [0] * k
circular queue에서 front/rear index 저장
!!!
"""
class MyCircularDeque:

    def __init__(self, k: int):
        self.deque = [0] *  k
        self.size = 0
        self.capacity = k
        self.front = 0
        self.rear = -1

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        self.front = (self.front - 1) % self.capacity
        self.deque[self.front] = value
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        self.rear = (self.rear + 1) % self.capacity
        self.deque[self.rear] = value
        self.size += 1
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        self.rear = (self.rear - 1) % self.capacity
        self.size -= 1
        return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.deque[self.front]

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.deque[self.rear]

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.capacity