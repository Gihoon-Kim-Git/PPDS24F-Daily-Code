class Solution(object):
    def carPooling(self, trips, capacity):
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        total_passengers = sum([x[0] for x in trips])
        if total_passengers > capacity:
            return False
        else:
            return True