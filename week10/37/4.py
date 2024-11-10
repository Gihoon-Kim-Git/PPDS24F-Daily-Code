class ExamRoom:

    def __init__(self, n: int):
        self.n = n
        self.seats = []

    def seat(self) -> int:
        if not self.seats:
            student = 0
        else:
            max_dist = self.seats[0]
            student = 0
            
            for i in range(1, len(self.seats)):
                prev, curr = self.seats[i - 1], self.seats[i]
                dist = (curr - prev) // 2
                if dist > max_dist:
                    max_dist = dist
                    student = prev + dist

            if self.n - 1 - self.seats[-1] > max_dist:
                student = self.n - 1

        index = 0
        while index < len(self.seats) and self.seats[index] < student:
            index += 1
        self.seats.insert(index, student)
        
        return student

    def leave(self, p: int) -> None:
        self.seats.remove(p)
