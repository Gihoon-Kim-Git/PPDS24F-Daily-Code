from heapq import heappop, heappush

class ExamRoom:

    def __init__(self, n: int):
        self.n = n
        self.heap = []
        self.avail_first = {}
        self.avail_last = {}
        self.put_segment(0, self.n - 1)

    def put_segment(self, first, last):
        if first == 0 or last == self.n - 1:
            priority = last - first
        else:
            priority = (last - first) // 2
        
        segment = [-priority, first, last, True]

        self.avail_first[first] = segment
        self.avail_last[last] = segment

        heappush(self.heap, segment)

    def seat(self) -> int:
        while True:
            _, first, last, is_vaild = heappop(self.heap)

            if is_vaild:
                del self.avail_first[first]
                del self.avail_last[last]
                break
        if first == 0:
            ret = 0
            if first != last:
                self.put_segment(first + 1, last)

        elif last == self.n - 1:
            ret = last
            if first != last:
                self.put_segment(first, last - 1)

        else:
            ret = first + (last - first) // 2
            if ret > first:
                self.put_segment(first, ret - 1)
            if ret < last:
                self.put_segment(ret + 1, last)
        return ret
         
    def leave(self, p: int) -> None:
        first = p
        last = p

        left = p - 1
        right = p + 1

        if left >= 0 and left in self.avail_last:
            segment_left = self.avail_last.pop(left)
            segment_left[3] = False
            first = segment_left[1]

        if right < self.n and right in self.avail_first:
            segment_right = self.avail_first.pop(right)
            segment_right[3] = False
            last = segment_right[2]

        self.put_segment(first, last)
        


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)