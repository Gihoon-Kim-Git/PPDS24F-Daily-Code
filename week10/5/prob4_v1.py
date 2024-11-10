# Time Limit Exceeded

class ExamRoom:

    def __init__(self, n: int):
        self.seats = [False for _ in range(n)]
        self.dists = [n for _ in range(n)]

    def seat(self) -> int:
        # argmax dists 찾기
        argmax = 0
        for i in range(len(self.dists)):
            if self.dists[i] > self.dists[argmax]:
                argmax = i
        # self.seats 업데이트
        self.seats[argmax] = True
        # self.dists 업데이트
        for i in range(len(self.dists)):
            dist = abs(i - argmax)
            self.dists[i] = min(self.dists[i], dist)
        return argmax

    def leave(self, p: int) -> None:
        # print("Before")
        # print(f"seats: {self.seats}")
        # print(f"dists: {self.dists}")

        # self.seats 업데이트
        self.seats[p] = False
        # self.dists 업데이트
        # - 왼쪽방향으로 가장 가까운 기존좌석 찾기
        left = 0
        for i in range(p-1, -1, -1):
            if self.seats[i]:
                left = i
                break
        # - 오른쪽방향으로 가장 가까운 기존좌석 찾기
        right = len(self.seats) - 1
        for i in range(p+1, len(self.seats)):
            if self.seats[i]:
                right = i
                break
        # - left 와 right 사이 dist 를 inf 로 설정
        for i in range(left, right+1):
            self.dists[i] = len(self.dists)
        # - left 와 right 에 좌석 존재하는 경우, 그에 따른 self.dists 업데이트
        if self.seats[left]:
            for i in range(left, right+1):
                dist = i - left
                self.dists[i] = min(self.dists[i], dist)
        if self.seats[right]:
            for i in range(right, left-1, -1):
                dist = right - i
                self.dists[i] = min(self.dists[i], dist)

        # print(f"After {p}")
        # print(f"seats: {self.seats}")
        # print(f"dists: {self.dists}")
        # print()
        


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)
