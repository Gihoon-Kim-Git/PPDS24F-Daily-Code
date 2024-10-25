class MyCalendarTwo(object):

    def __init__(self):
        self.reserved = []  # 안전하게 booking 완료된 날짜들
        self.overlap = []   # 중첩되는 구간들 (이미 2개가 겹친다는 뜻. 여기서 하나라도 더 겹치면 triple)
        
    def check_overlap(self, r1, r2):   # r = (start,end)
        if r1[1] <= r2[0] or r1[0] >= r2[1]:
            return False
        return True


    def book(self, start, end):

        for r in self.overlap:
            if self.check_overlap(r, (start,end)):
                return False     # triple

        for (start_r, end_r) in self.reserved:
            if self.check_overlap((start_r, end_r), (start,end)):
                self.overlap.append((max(start_r, start), min(end_r, end)))

        self.reserved.append((start,end))
        return True
        




myCalendarTwo = MyCalendarTwo()
print(myCalendarTwo.book(10, 20))
print(myCalendarTwo.book(50, 60)) 
print(myCalendarTwo.book(10, 40)) 
print(myCalendarTwo.book(5, 15))   # False
print(myCalendarTwo.book(5, 10)) 
print(myCalendarTwo.book(25, 55))  # True


