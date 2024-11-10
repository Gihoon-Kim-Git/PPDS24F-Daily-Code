class MyCalendarTwo:

    def __init__(self):
        self.s1 = set()        
        self.s2 = set()        
    def book(self, start: int, end: int) -> bool:
        for s,e in self.s2 :
            if start < e and end > s : return False
        
        for s,e in self.s1:
            if start < e and end > s :
                self.s2.add((max(start,s),min(end,e)))
        
        self.s1.add((start,end))
        return True

# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)