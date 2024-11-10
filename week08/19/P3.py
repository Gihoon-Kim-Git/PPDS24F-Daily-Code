class LinkedNode():
    def __init__(self, x):
        self.val = x
        self.next = None

class MyCircularDeque(object):

    def __init__(self, k):
        
        self.sentinel = LinkedNode(-1)
        self.size = 0
        self.capa = k

    def insertFront(self, value):
        if (self.size >= self.capa):
            return False
        newFront = LinkedNode(value)
        newFront.next = self.sentinel.next
        self.sentinel.next = newFront
        self.size += 1
        return True

    def insertLast(self, value):
        if (self.size >= self.capa):
            return False
        curNode = self.sentinel
        while curNode.next:
            curNode = curNode.next
        curNode.next = LinkedNode(value)
        self.size += 1
        return True

    def deleteFront(self):
        try:
            self.sentinel.next = self.sentinel.next.next
        except:
            return False
        self.size -= 1
        return True

    def deleteLast(self):
        try:
            curNode = self.sentinel
            while curNode.next.next:
                curNode = curNode.next
            curNode.next = None
        except:
            return False
        self.size -= 1
        return True

    def getFront(self):
        if self.sentinel.next:
            return self.sentinel.next.val
        return -1

    def getRear(self):
        curNode = self.sentinel
        while curNode.next:
            curNode = curNode.next
        return curNode.val

    def isEmpty(self):
        if self.size == 0:
            return True
        return False

    def isFull(self):
        if self.size == self.capa:
            return True
        return False

if __name__ == "__main__":
    myCircularDeque = MyCircularDeque(3)
    print(myCircularDeque.insertLast(1))
    print(myCircularDeque.insertLast(2))
    print(myCircularDeque.insertFront(3))
    print(myCircularDeque.insertFront(4))
    print(myCircularDeque.getRear())
    print(myCircularDeque.isFull())
    print(myCircularDeque.deleteLast())
    print(myCircularDeque.insertFront(4))
    print(myCircularDeque.getFront())