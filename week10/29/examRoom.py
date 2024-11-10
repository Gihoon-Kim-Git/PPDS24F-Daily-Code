"""
<Exam Room>

There is an exam room with n seats in a single row labeled from 0 to n - 1.

When a student enters the room, they must sit in the seat that maximizes the distance to the closest person. 
If there are multiple such seats, they sit in the seat with the lowest number. 
If no one is in the room, then the student sits at seat number 0.

Design a class that simulates the mentioned exam room.

Implement the ExamRoom class:

- ExamRoom(int n): Initializes the object of the exam room with the number of the seats n.
- int seat(): Returns the label of the seat at which the next student will set.
- void leave(int p): Indicates that the student sitting at seat p will leave the room. It is guaranteed that there will be a student sitting at seat p. 
"""

class ExamRoom:
    def __init__(self, n):
        self.n = n
        self.seats = [False for _ in range(n)]
        self.ppl = 0

    def seat(self):
        if self.ppl == 0: 
            self.seats[0] = True
            self.ppl += 1
            return 0

        max_dist = -1
        seat_to_sit = 0

        prev_seat = -1
        for i in range(self.n):
            if self.seats[i]:  
                if prev_seat == -1:  
                    dist = i
                else:  
                    dist = (i - prev_seat) // 2

                if dist > max_dist:
                    max_dist = dist
                    seat_to_sit = prev_seat + dist if prev_seat != -1 else 0

                prev_seat = i

        if prev_seat != -1 and self.n - 1 - prev_seat > max_dist:
            seat_to_sit = self.n - 1

        self.seats[seat_to_sit] = True
        self.ppl += 1
        return seat_to_sit

    def leave(self, p):
        self.seats[p] = False
        self.ppl -= 1



examRoom = ExamRoom(10)
print(examRoom.seat()) # return 0, no one is in the room, then the student sits at seat number 0.
print(examRoom.seat()) # return 9, the student sits at the last seat number 9.
print(examRoom.seat()) # return 4, the student sits at the last seat number 4.
print(examRoom.seat()) # return 2, the student sits at the last seat number 2.
examRoom.leave(4)
print(examRoom.seat()) # return 5, the student sits at the last seat number 5.
