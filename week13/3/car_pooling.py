# You are given the integer capacity and an array `trips` where trips[i] = [numPassengers, from, to]
# indicates that the ith trip has `numPassengers` passengers, and the locations to pick them up
# and drop them off are `from` and `to`, respectively.
#
# The vehicle only drives east (i.e., it cannot turn around and drive west).
#
# Return True if it is possible to pick up and drop off all passengers for all the given trips, or False otherwise.
#
# Example 1:
# Input: trips = [[2, 1, 5], [3, 3, 7]], capacity = 4
# Output: False
#
# Example 2:
# Input: trips = [[2, 1, 5], [3, 3, 7]], capacity = 5
# Output: True
#
# Constraints:
# - 1 <= trips.length <= 1000
# - trips[i].length == 3
# - 1 <= numPassengers <= 100
# - 0 <= from < to <= 1000
# - 1 <= capacity <= 10^5


def bubble_sort(arr):
    """
    Custom bubble sort function to sort events. (ascending order)
    Sort by location first, and if locations are the same, sort by passenger change.
    """
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            # Compare current event and the next event
            # Sort by location; if equal, sort by passenger change
            if arr[j][0] > arr[j + 1][0] or (
                arr[j][0] == arr[j + 1][0] and arr[j][1] > arr[j + 1][1]
            ):
                # Swap arr[j] and arr[j + 1]
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def carPooling(trips, capacity):
    """
    Determine if it is possible to pick up and drop off all passengers
    without exceeding the car's capacity.
    
    :param trips: List of trips where each trip is [numPassengers, from, to].
    :param capacity: Maximum number of passengers the car can hold.
    :return: True if all trips can be completed within capacity, False otherwise.
    """
    if len(trips) == 0:
        return True # no passengers exist
    
    # Extract Events:
    # For each trip [numPassengers, from, to], create two events:
    # Pickup at from (+numPassengers).
    # Drop-off at to (-numPassengers).
    events = []
    for trip in trips:
        numPassengers, pickUp, dropOff = trip
        events.append((pickUp, +numPassengers))
        events.append((dropOff, -numPassengers))

    # Sort Events:
    # Sort by location, and if two events are at the same location, prioritize drop-off over pickup.
    bubble_sort(events)

    # Simulate Passenger Flow:
    # Traverse the sorted events, maintain a running total of passengers, and check if it exceeds the capacity.
    curr = 0 # tracking the number of current passengers
    for event in events:
        location, passengerChange =  event
        curr += passengerChange
        # print("location: ", location, "curr: ", curr)
        if curr > capacity:
            return False
    
    # If we processed all events without exceeding capacity, return True
    return True


# Example test cases
def test_carPooling():
    assert carPooling([[2, 1, 5], [3, 3, 7]], 4) == False, "Test Case 1 Failed"
    assert carPooling([[2, 1, 5], [3, 3, 7]], 5) == True, "Test Case 2 Failed"
    assert carPooling([[2, 2, 5], [3, 5, 7]], 4) == True, "Test Case 3 Failed"
    assert carPooling([[3, 2, 8], [4, 4, 6], [10, 1, 3]], 11) == False, "Test Case 4 Failed"
    print("All Test Cases Passed!")

# Uncomment to test
# test_carPooling()