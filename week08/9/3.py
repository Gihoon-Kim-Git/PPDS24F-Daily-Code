class MyCircularDeque:

    def __init__(self, k: int):
        self.k = k  # Maximum size of the deque
        self.deque = [None] * k  # Initialize deque with None
        self.front = 0  # Pointer to the front
        self.rear = 0  # Pointer to the rear
        self.size = 0  # Track current size of deque

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        # Move front pointer backwards in a circular way
        self.front = (self.front - 1) % self.k
        self.deque[self.front] = value
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        # Insert at rear and move rear pointer forward in a circular way
        self.deque[self.rear] = value
        self.rear = (self.rear + 1) % self.k
        self.size += 1
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        # Move front pointer forward in a circular way
        self.deque[self.front] = None
        self.front = (self.front + 1) % self.k
        self.size -= 1
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        # Move rear pointer backwards in a circular way
        self.rear = (self.rear - 1) % self.k
        self.deque[self.rear] = None
        self.size -= 1
        return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.deque[self.front]

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        # Rear is one step ahead, so we get the previous element in a circular way
        return self.deque[(self.rear - 1) % self.k]

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.k