#MyCalendarTwo
class MyCalendarTwo:

    def __init__(self):
        # List of single and double bookings
        self.single_bookings = []
        self.double_bookings = []

    def book(self, start: int, end: int) -> bool:
        # Check for any overlap with double bookings (would result in triple booking)
        for dbl_start, dbl_end in self.double_bookings:
            if max(start, dbl_start) < min(end, dbl_end):  # If there's an overlap with double bookings
                return False
        
        # Check for overlaps with single bookings and prepare to add the overlap to double bookings
        for sng_start, sng_end in self.single_bookings:
            overlap_start = max(start, sng_start)
            overlap_end = min(end, sng_end)
            if overlap_start < overlap_end:  # There's an overlap
                self.double_bookings.append((overlap_start, overlap_end))
        
        # If no triple booking, add the event to single bookings
        self.single_bookings.append((start, end))

        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)