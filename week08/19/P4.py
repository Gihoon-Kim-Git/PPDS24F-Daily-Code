class LinkedNode():
    def __init__(self, x, y):
        self.val = x
        self.next = None
        self.min = y

class MinStack(object):

    def __init__(self):
        
        self.sentinel = LinkedNode(-2**31, -2**31)

    def push(self, value):
        if (self.sentinel.next and self.sentinel.next.min < value):
            top = LinkedNode(value, self.sentinel.next.min)
            top.next = self.sentinel.next
            self.sentinel.next = top
        else:
            top = LinkedNode(value, value)
            top.next = self.sentinel.next
            self.sentinel.next = top

    def pop(self):
        try:
            self.sentinel.next = self.sentinel.next.next
        except:
            return None

    def top(self):
        if self.sentinel.next:
            return self.sentinel.next.val
        return None

    def getMin(self):
        return self.sentinel.next.min

if __name__ == "__main__":
    minStack = MinStack()
    print(minStack.push(-2))
    print(minStack.push(0))
    print(minStack.push(-1))
    print(minStack.getMin())
    print(minStack.top())
    print(minStack.pop())
    print(minStack.getMin())