class MyCalendarTwo:

    def __init__(self):
        self.events = []


    def book(self, start: int, end: int) -> bool:
        overlap_area = []
        for i, e in enumerate(self.events):
            if max(start, e[0]) < min(end, e[1]):
                overlap_area.append((max(start, e[0]), min(end, e[1])))
        for i in range(len(overlap_area)):
            s1, e1 = overlap_area[i]
            for j in range(i+1, len(overlap_area)):
                s2, e2 = overlap_area[j]
                if max(s1, s2) < min(e1, e2):
                    return False
        self.events.append([start, end])
        return True
                
            

                

            
        self.events.append([start, end])
        return True
            
        


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)