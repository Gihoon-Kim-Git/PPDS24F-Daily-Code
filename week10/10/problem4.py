import bisect 

class ExamRoom:

    def __init__(self, n: int):
        self.n, self.room = n, []

    def seat(self) -> int:
        if not self.room: 
            ans = 0                           
        else:
            dist, prev, ans = self.room[0], self.room[0], 0 

            for curr in self.room[1:]:                   
                d = (curr - prev)//2
                if dist < d: 
                    dist, ans = d, (curr + prev)//2
                prev = curr

            if dist < self.n - prev-1: 
                ans = self.n - 1     

        bisect.insort(self.room, ans)                              

        return ans

    def leave(self, p: int) -> None:
        self.room.remove(p)