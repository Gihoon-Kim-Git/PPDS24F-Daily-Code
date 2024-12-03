"""
<Car Pooling>

There is a car with capacity empty seats. 
The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips 
where trips[i] = [numPassengers_i, from_i, to_i] indicates that the ith trip has numPassengers_i passengers 
and the locations to pick them up and drop them off are from_i and to_i respectively. 
The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
"""

def carPooling(trips,capacity):
    """
    Record passenger changes at each location (from_i에서 추가, to_i에서 빼기)
    Check if the cumulative count exceeds the car's capacity at any point
    """
    passenger_changes = {}

    for num_passengers, start, end in trips:
        passenger_changes[start] = passenger_changes.get(start,0) + num_passengers
        passenger_changes[end] = passenger_changes.get(end,0) - num_passengers
        
    current_passengers = 0
    for location in sorted(passenger_changes.keys()):   # location 순서대로 (가까운 곳 -> 먼 곳) 누적값 계산
        current_passengers += passenger_changes[location]
        if current_passengers > capacity:
            return False

    return True


print(carPooling([[2,1,5],[3,3,7]],4))  # false
print(carPooling([[2,1,5],[3,3,7]],5))  # true