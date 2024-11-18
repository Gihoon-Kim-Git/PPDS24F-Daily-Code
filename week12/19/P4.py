class LinkedNode():
    def __init__(self, x):
        self.val = x
        self.next = None

class MyQueue(object):

    def __init__(self):
        self.sentinel = LinkedNode(-999)
        self.size = 0    

    def push(self, x):
        curNode = self.sentinel
        while curNode.next:
            curNode = curNode.next
        curNode.next = LinkedNode(x)
        self.size += 1

    def pop(self):
        if self.empty():
            return None
        front = self.sentinel.next.val
        self.sentinel.next = self.sentinel.next.next
        self.size -= 1
        return front

    def peek(self):
        if self.empty():
            return None
        return self.sentinel.next.val

    def empty(self):
        return self.size == 0
        
if __name__ == "__main__":
    obj = MyQueue()
    obj.push(1)
    obj.push(2)
    print(obj.peek())
    print(obj.pop())
    print(obj.empty())