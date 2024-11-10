class ExamRoom:
    def __init__(self, n: int):
        self.n = n
        self.seats = []

    def seat(self) -> int:
        # 자리에 아무도 없으면 0번에 앉게 됨
        if not self.seats:
            self.seats.append(0)
            return 0
        # 자리가 비어 있으면 seat 0번도 고려하여야 함
        max_distance = self.seats[0]
        seat_to_sit = 0

        # occupied seats 간의 거리 check
        for i in range(1, len(self.seats)):
            prev_seat = self.seats[i - 1]
            next_seat = self.seats[i]
            distance = (next_seat - prev_seat) // 2
            if distance > max_distance:
                max_distance = distance
                seat_to_sit = prev_seat + distance

        # 마지막 occupied seat와 제일 끝자리 seat와의 거리 체크
        if self.n - 1 - self.seats[-1] > max_distance:
            seat_to_sit = self.n - 1

        # 착석 후 seats 를 sort하여 정렬
        self.seats.append(seat_to_sit)
        self.seats.sort()
        return seat_to_sit

    def leave(self, p: int) -> None:
        self.seats.remove(p)

# Your ExamRoom object will be instantiated and called as such:
"""
input = ["ExamRoom","seat","seat","seat","leave","leave","seat","seat","seat","seat","seat", "seat","seat","seat","seat","leave","leave","seat","seat","leave","seat","leave","seat","leave","seat","leave","seat","leave","leave","seat","seat","leave","leave","seat","seat","leave"]
inputval = [[10],[],[],[],[0],[4],[],[],[],[],[],[],[],[],[],[0],[4],[],[],[7],[],[3],[],[3],[],[9],[],[0],[8],[],[],[0],[8],[],[],[2]]


input = ["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"]
inputval = [[10], [], [], [], [], [4], []]


input = ["ExamRoom","seat","seat","seat","leave","leave","seat","seat","seat","seat","seat","seat","seat"]
inputval = [[8],[],[],[],[0],[7],[],[],[],[],[],[],[]]
"""
input = ["ExamRoom","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","leave","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat","seat"]

inputval = [[1000000],[],[],[],[],[],[],[],[],[],[],[],[624999],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[]]

result = []

# 테스트 환경 구현, output check 용도
for i in range(len(input)):
    #print(i, input[i], inputval[i])
    if input[i] == "ExamRoom":
        obj = ExamRoom(inputval[i][0])
        result.append(None)
    elif input[i] == "seat":
        result.append(obj.seat())
    elif input[i] == "leave":
        result.append(obj.leave(inputval[i][0]))
    #print(obj.seats)

print(result)

