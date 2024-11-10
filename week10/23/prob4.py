# 855. Exam Room
import heapq

class ExamRoom(object):
    def __init__(self, n):
        """
        :type n: int
        """
        self.n = n
        # max Heap
        self.maxHeap = []

    def seat(self):
        """
        :rtype: int
        """
        if not self.maxHeap:
            left, right = -1, self.n
        else:
            top = heapq.heappop(self.maxHeap)
            left, right = top[1], top[2]
        # when empty:
        if left == -1:
            seat = 0
        # when no occupied seat on "right"
        elif right == self.n:
            seat = self.n -1
        else:
            seat = (left+right)//2
        
        closestDistance_left = (seat - left) // 2
        if left == -1:
            closestDistance_left = seat
        closestDistance_right = (right - seat) // 2
        if right == self.n:
            closestDistance_right = self.n - 1 - seat
        heapq.heappush(self.maxHeap, [-closestDistance_left, left, seat])
        heapq.heappush(self.maxHeap, [-closestDistance_right, seat, right])
        return seat

    def leave(self, p):
        """
        :type p: int
        :rtype: None
        """
        intervalStartsAtP = None
        intervalEndsAtP = None
        for interval in self.maxHeap:
            if interval[1] == p:
                intervalStartsAtP = interval
            if interval[2] == p:
                intervalEndsAtP = interval
        self.maxHeap.remove(intervalStartsAtP)
        self.maxHeap.remove(intervalEndsAtP)
        heapq.heapify(self.maxHeap)

        left = intervalEndsAtP[1]
        right = intervalStartsAtP[2]

        closestDistance = (right - left) // 2
        if left == -1:
            closestDistance = right
        elif right == self.n:
            closestDistance = self.n - 1 - left
        heapq.heappush(self.maxHeap, [-closestDistance, left, right])


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)