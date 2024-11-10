class ExamRoom:


    def __init__(self, n: int):
        self.n, self.room = n, []

    def seat(self) -> int:
        if not self.room:
            ans = 0
        else:
            dist, prev, ans = self.room[0], self.room[0], 0

            for curr in self.room[1:]:
                d = (curr - prev) // 2

                if dist < d:
                    dist, ans = d, (curr+prev) // 2
                prev = curr

            if dist < self.n - prev - 1:
                ans = self.n - 1

        insort(self.room ,ans)

        return ans

    def leave(self, p: int):
        self.room.remove(p)
        

# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)