# event의 시작, 종료 시간이 주어질 때 3개의 event가 겹치면 calendar에 등록되지 않음 (return False)
# 아니면 return True

class MyCalendarTwo:

    def __init__(self):
        self.schedule = []
        self.double = []

    def book(self, start: int, end: int) -> bool:
        def isOverlap(book1, book2):
            start1, end1 = book1[0], book1[1]
            start2, end2 = book2[0], book2[1]
            if start1 <= start2 and start2 < end1:
                return True
            elif  start1 < end2 and end2 <= end1:
                return True
            elif start2 <= start1 and end1 <= end2:
                return True
            else:
                return False
        overlap = []
        new = (start, end)
        for book in self.schedule:
            if isOverlap(book, new):
                for d_book in self.double:
                    if isOverlap(d_book, new):
                        return False
                overlap.append((max(book[0], start), min(book[1], end)))

        self.schedule.append((start,end))
        self.double += overlap
        return True