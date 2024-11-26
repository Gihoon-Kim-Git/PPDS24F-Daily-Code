class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        #trips[i] = [numPassengersi, fromi, toi]
        events=[]
        for num, start, dest in trips:
            events.append((start,num))
            events.append((dest,-num))

        events.sort(key=lambda x: (x[0], x[1]))
        curr=0
        for event in events:
            curr+=event[1]
            if curr >capacity:
                return False
        return True
