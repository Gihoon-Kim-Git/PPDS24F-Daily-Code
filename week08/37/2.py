class MyCalendarTwo:

    def __init__(self):
        self.bookings = []
        self.overlaps = []

    def book(self, start: int, end: int) -> bool:
        for overlap_start, overlap_end in self.overlaps:
            if start < overlap_end and end > overlap_start:
                return False

        for booking_start, booking_end in self.bookings:
            if start < booking_end and end > booking_start:
                self.overlaps.append((max(start, booking_start), min(end, booking_end)))

        self.bookings.append((start, end))
        return True
