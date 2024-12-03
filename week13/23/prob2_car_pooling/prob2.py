def carPooling(trips, capacity):
    events = []
    for num_passengers, start, end in trips:
        events.append((start, num_passengers))  # Passenger pickup
        events.append((end, -num_passengers))  # Passenger drop-off

    # Sort events by location and in case of tie, by type (drop-off before pickup)
    events.sort()

    current_passengers = 0
    for location, passengers_change in events:
        current_passengers += passengers_change
        if current_passengers > capacity:
            return False

    return True

# Example usage
trips = [[2, 1, 5], [3, 3, 7]]
capacity = 4
print(carPooling(trips, capacity))  # Output: False
