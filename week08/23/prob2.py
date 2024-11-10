class MyCalendarTwo:
    def __init__(self):
        self.single = []
        self.double_booked = []
    def book(self, start, end):
        for s, e in self.double_booked:
            if max(start, s) < min(end, e):
                return False
        # Add the overlapping parts to double booking
        for s, e in self.single:
            if max(start, s) < min(end, e):
                self.double_booked.append((max(start, s), min(end, e)))
        # add the event to single bookings
        self.single.append((start, end))
        return True
    

# Driver Code
if __name__=="__main__":
    cal = MyCalendarTwo()

    # Bookings
    print(cal.book(10, 20))  # True
    print(cal.book(50, 60))  # True
    print(cal.book(10, 40))  # True
    print(cal.book(5, 15))   # False (would cause a triple booking)
    print(cal.book(5, 10))   # True
    print(cal.book(25, 55))  # True
