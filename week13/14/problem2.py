# week 13

# Tuesday. [Car Pooling](https://leetcode.com/problems/car-pooling/description/)

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        locations = []
        for numPassengers, start, end in trips:
            locations.extend([(start, numPassengers), (end, -numPassengers)])
        locations.sort()

        for _, numPassengers in locations:
            capacity -= numPassengers
            if capacity < 0: return False

        return True