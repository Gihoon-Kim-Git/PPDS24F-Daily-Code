class Solution(object):
    def carPooling(self, trips, capacity):
        timeline = [0] * 1001
        for numPassengers, fromi, toi in trips:
            timeline[fromi] += numPassengers
            timeline[toi] -= numPassengers
        current_passengers = 0
        for passengers in timeline:
            current_passengers += passengers
            if current_passengers > capacity:
                return False
        return True
