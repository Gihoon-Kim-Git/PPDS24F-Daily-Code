import heapq
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        changes = []
        
        for num_passengers, start, end in trips:
            changes.append((start, num_passengers))  # Picking up passengers
            changes.append((end, -num_passengers))  # Dropping off passengers
        
        # Sort the changes based on location, and in case of ties, by type of change
        changes.sort(key=lambda x: (x[0], x[1]))
        
        current_passengers = 0
        for location, change in changes:
            current_passengers += change
            # If at any point current passengers exceed capacity, return False
            if current_passengers > capacity:
                return False
        
        # If no capacity violations occurred, return True
        return True