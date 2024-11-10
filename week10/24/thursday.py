from bisect import insort

class ExamRoom:
    def __init__(self, n: int):
        self.n, self.room = n, []

    def seat(self) -> int:
        # sit at 0 if empty room
        if not self.room: ans = 0

        else:
            # set best between door and first student
            dist, prev, ans = self.room[0], self.room[0], 0

            # check between all pairs of students  
            for curr in self.room[1:]:
                # to improve on current best              
                d = (curr - prev)//2                        

                if dist < d: dist, ans = d, (curr + prev)//2
                prev = curr

            # finally, check whether last seat is best
            if dist < self.n - prev-1: ans = self.n - 1     

        # sit down in best seat
        insort(self.room, ans)                              

        return ans

    def leave(self, p: int) -> None:
        self.room.remove(p)