# Given an array A consisting of N integers, where each element represents the daily price of a stock share
# over a period of N consecutive days, the goal is to determine the maximum possible profit from a single
# buy-and-sell transaction. The buy must occur on or before the sell day (0 ≤ P ≤ Q < N).
# If it's impossible to make any profit, the function should return 0.
#
# Example:
# A = [23171, 21011, 21123, 21366, 21013, 21367]
# The best transaction would be buying on day 1 at price 21011 and selling on day 5 at price 21367,
# resulting in a profit of 356. The function should return 356.
#
# Constraints:
# - N is an integer within the range [0..400,000]
# - Each element of array A is an integer within the range [0..200,000]

def solution(A):
    # no prices or less than one price: no transaction possible
    if (not A) or (len(A) <= 1):
        return 0
    
    # MY SOLUTION: time complexity O(N**2)
    max_profit = 0
    for i in range(len(A)):
        for j in range(i+1, len(A)):
            curr_profit = A[j] - A[i]
            if curr_profit > max_profit:
                max_profit = curr_profit
    
    """
    # GPT SOLUTION
    # initialization: variables to keep track of the minimum price encountered so far and the maximum profit
    min_price = A[0]
    max_profit = 0

    # iteration through each price in the array, starting from second element
    for price in A[1:]:
        # calculate potential profit if we were to sell at current price
        curr_profit = price - min_price
        # update max_profit
        if curr_profit > max_profit:
            max_profit = curr_profit
        # update min_price if current price is lower than the previously recorded minimum price
        if price < min_price:
            min_price = price
    """
    
    return max_profit

# Example Usage
A = [23171, 21011, 21123, 21366, 21013, 21367]
print(solution(A))  # Output: 356