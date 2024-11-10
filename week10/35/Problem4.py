# leetcode 855
import bisect

class ExamRoom:

    def __init__(self, n: int):
        self.n = n
        self.students = []

    def seat(self) -> int:
        if not self.students:
            student = 0
        else:
            max_dist = self.students[0]
            student = 0
            for i in range(len(self.students) - 1):
                prev, curr = self.students[i], self.students[i + 1]
                dist = (curr - prev) // 2
                if dist > max_dist:
                    max_dist = dist
                    student = prev + dist
            if self.n - 1 - self.students[-1] > max_dist:
                student = self.n - 1
        bisect.insort(self.students, student)
        return student

    def leave(self, p: int) -> None:
        self.students.remove(p)
