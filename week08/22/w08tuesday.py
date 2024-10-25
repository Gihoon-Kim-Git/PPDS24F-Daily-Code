
class MyCalendarTwo:

    def __init__(self):
        self.events = []
        self.overlaps = []

    def book(self, start, end):
        for o_start, o_end in self.overlaps:
            if max(start, o_start) < min(end, o_end):
                return False

        for e_start, e_end in self.events:
            if max(start, e_start) < min(end, e_end):
                overlap_start = max(start, e_start)
                overlap_end = min(end, e_end)
                self.overlaps.append((overlap_start, overlap_end))

        self.events.append((start, end))
        return True