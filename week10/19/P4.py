class ExamRoom(object):
    def __init__(self, n):
        self.room = []
        self.interval = [n-1]
        self.n = n

    def seat(self):
        if (self.room == []):
            self.room.append(0)
            self.interval = [0] + self.interval
            return 0
        if (self.room[0] != 0):
            self.interval[0] *= 2
        if (self.room[-1] != self.n-1):
            self.interval[-1] *= 2
        maxlen = max(self.interval) // 2 * 2
        offset = 0
        for i in range(len(self.interval)):
            if (self.interval[i] >= maxlen):
                offset += maxlen//2
                if (i == 0 and self.room[0] != 0):
                    offset = 0
                break
            if (i == 0 and self.room[0] != 0):
                offset += self.interval[0]//2
            else:
                offset += self.interval[i]
        for j in range(len(self.room)):
            if (self.room[j] > offset and j == 0):
                self.room = [offset] + self.room
                self.interval = [0] + [self.interval[0]//2] + self.interval[1:]
            elif (self.room[j] < offset and j == len(self.room)-1):
                self.room.append(offset)
                self.interval = self.interval[:-1] + [self.interval[-1]//2] + [0]
            elif (self.room[j] < offset < self.room[j+1]):
                self.room = self.room[:j+1] + [offset] + self.room[j+1:]
                self.interval = self.interval[:j+1] + [maxlen//2] + [self.interval[j+1]-maxlen//2] + self.interval[j+2:]
        if (self.room[0] != 0):
            self.interval[0] //= 2
        if (self.room[-1] != self.n-1):
            self.interval[-1] //= 2
        print(f"maxlen : {maxlen}, offset : {offset}")
        print(f"room : {self.room}, interval : {self.interval}")
        return offset

    def leave(self, p):
        i = self.room.index(p)
        self.room = self.room[:i] + self.room[i+1:]
        self.interval = self.interval[:i] + [self.interval[i]+self.interval[i+1]] + self.interval[i+2:]
        print(f"room : {self.room}, interval : {self.interval}")
        return

if __name__ == "__main__":
    obj = ExamRoom(8)
    obj.seat()
    obj.seat()
    obj.seat()
    obj.leave(0)
    obj.leave(7)
    obj.seat()
    obj.seat()
    obj.seat()
    obj.seat()
    obj.seat()
    obj.seat()
    obj.seat()