# 0부터 n−1까지 번호가 매겨진 n개의 좌석이 일렬로 배치되어 있을 때
# 가장 가까운 사람과의 거리가 최대가 되는 좌석에 착석
# 단, 여러 개의 좌석이 그러한 경우 가장 번호가 낮은 좌석 선택
# 또한 아무도 없다면 0번 좌석 선택

"""
GPT 풀이
"""

class ExamRoom:

    def __init__(self, n: int):
        self.n = n
        self.seats = []

    def seat(self) -> int:
        # No students in the room
        if not self.seats:
            student = 0
        else:
            # Initialize the maximum distance and student position
            max_dist = self.seats[0]
            student = 0
            
            # Check distances between consecutive students
            for i in range(1, len(self.seats)):
                prev, next = self.seats[i - 1], self.seats[i]
                dist = (next - prev) // 2
                if dist > max_dist:
                    max_dist = dist
                    student = prev + dist

            # Check distance to the last seat
            if self.n - 1 - self.seats[-1] > max_dist:
                student = self.n - 1

        # Place the student at the selected seat and keep the seats sorted
        self.seats.append(student)
        self.seats.sort()
        return student

    def leave(self, p: int) -> None:
        self.seats.remove(p)


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)