class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        timeline = []
        for passengers, start, end in trips:
            timeline.append((start, passengers))
            timeline.append((end, -passengers))
        
        timeline.sort()
        current_capacity = 0
        
        for _, change in timeline:
            current_capacity += change
            if current_capacity > capacity:
                return False
        
        return True
