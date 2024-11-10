class MyCircularDeque(object):

    def __init__(self, k):
        """
        :type k: int
        """
        self.max_size = k
        self.front_idx = 0
        self.rear_idx = 0
        self.cdq = []
    
    def insertFront(self, value):
        """
        :type value: int
        :rtype: bool
        """
        if not self.isFull():
            self.cdq.insert(self.front_idx, value)
            self.rear_idx += 1
            # print(self.cdq)
            return True
        return False
        
        
    def insertLast(self, value):
        """
        :type value: int
        :rtype: bool
        """
        if not self.isFull():
            self.cdq.append(value)
            self.rear_idx += 1
            # print(self.cdq)
            return True
        return False
        

    def deleteFront(self):
        """
        :rtype: bool
        """
        if not self.isEmpty():
            del self.cdq[self.front_idx]
            self.rear_idx -= 1
            return True
        return False
        

    def deleteLast(self):
        """
        :rtype: bool
        """
        if not self.isEmpty():
            del self.cdq[self.rear_idx-1]
            self.rear_idx -= 1
            # print(self.cdq)
            return True
        return False

    def getFront(self):
        """
        :rtype: int
        """
        if not self.isEmpty():
            return self.cdq[self.front_idx]
        return -1
        

    def getRear(self):
        """
        :rtype: int
        """
        if not self.isEmpty():
            return self.cdq[self.rear_idx-1]
        return -1
        

    def isEmpty(self):
        """
        :rtype: bool
        """
        if len(self.cdq) == 0:
            return True
        return False
        

    def isFull(self):
        """
        :rtype: bool
        """
        if len(self.cdq) == self.max_size:
            return True
        return False


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


# myCircularDeque = MyCircularDeque(8)
# print(myCircularDeque.insertFront(5))  # [5]
# print(myCircularDeque.getFront())     
# print(myCircularDeque.isEmpty())
# print(myCircularDeque.deleteFront())   # []
# print(myCircularDeque.insertLast(3))   # [3]
# print(myCircularDeque.getRear())   
# print(myCircularDeque.insertLast(7))   # [3,7]
# print(myCircularDeque.insertFront(7))  # [7,3,7]
# print(myCircularDeque.deleteLast())
# print(myCircularDeque.insertLast(4))   # [7,3,4]
# print(myCircularDeque.isEmpty())

