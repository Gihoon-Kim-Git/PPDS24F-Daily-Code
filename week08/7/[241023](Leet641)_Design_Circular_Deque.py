"""문제
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
"""


"""Constraints
    1 <= k <= 1000
    0 <= value <= 1000
    At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.
"""

from collections import deque

class MyCircularDeque(object):

    def __init__(self, k):
        """
        :type k: int
        """
        self.max_len = k
        self.cur_len = 0
        self.que = deque()

    def insertFront(self, value):
        """
        :type value: int
        :rtype: bool
        """
        if self.cur_len >= self.max_len :
            return False
        else :
            self.que.appendleft(value)
            self.cur_len += 1
            
            return True
        

    def insertLast(self, value):
        """
        :type value: int
        :rtype: bool
        """
        if self.cur_len >= self.max_len :
            return False
        else :
            self.que.append(value)
            self.cur_len += 1
            
            return True

    def deleteFront(self):
        """
        :rtype: bool
        """
        if self.cur_len <= 0 :
            return False
        else :
            self.que.popleft()
            self.cur_len -= 1
            return True
        

    def deleteLast(self):
        """
        :rtype: bool
        """
        if self.cur_len <= 0 :
            return False
        else :
            self.que.pop()
            self.cur_len -= 1
            return True
    
    def getFront(self):
        """
        :rtype: int
        """
        if self.cur_len == 0:
            return -1
        else:
            return self.que[0]

    def getRear(self):
        """
        :rtype: int
        """
        if self.cur_len == 0:
            return -1
        else:
            return self.que[-1]
        

    def isEmpty(self):
        """
        :rtype: bool
        """
        if self.cur_len == 0:
            return True
        else :
            return False

    def isFull(self):
        """
        :rtype: bool
        """
        if self.cur_len == self.max_len :
            return True
        else :
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