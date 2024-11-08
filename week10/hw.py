#1. guess number
class Solution:
    def getMoneyAmount(self, n: int) -> int:
        # Initialize a DP table with (n+1)x(n+1) to cover all ranges 1 through n
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        
        # Fill the DP table for all ranges [l, r]
        for length in range(2, n + 1):  # Starting from subranges of length 2 up to n
            for l in range(1, n - length + 2):
                r = l + length - 1
                dp[l][r] = float('inf')  # Initialize to infinity
                for k in range(l, r):  # Try each guess `k` in the range
                    cost = k + max(dp[l][k - 1], dp[k + 1][r])  # Cost of guessing `k`
                    dp[l][r] = min(dp[l][r], cost)  # Minimum of all worst-case scenarios
        
        # The answer for range [1, n] is in dp[1][n]
        return dp[1][n]


#2. stone game 4
from typing import List

class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        # Count how many stones have remainder 0, 1, and 2
        count = [0, 0, 0]
        for stone in stones:
            count[stone % 3] += 1
        
        # If there are only stones with remainder 0, Alice loses.
        if count[0] % 2 == 0:
            # If both remainder-1 and remainder-2 stones are present and one can outweigh the other by more than 2,
            # Alice can avoid making a sum divisible by 3 on her turns.
            return count[1] > 0 and count[2] > 0
        else:
            # If count[0] is odd, then check the balance between count[1] and count[2].
            return abs(count[1] - count[2]) > 2


#3. minimum one bit operations
class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        def minOperations(x):
            if x == 0:
                return 0
            # Find the most significant bit (MSB) position
            k = x.bit_length() - 1
            # Recursive formula based on flipping the MSB
            return (1 << (k + 1)) - 1 - minOperations(x - (1 << k))
        
        return minOperations(n)


#4. exam room
import bisect

class ExamRoom:
    def __init__(self, n: int):
        self.n = n
        self.seats = []

    def seat(self) -> int:
        if not self.seats:
            # If no seats are occupied, sit at seat 0
            self.seats.append(0)
            return 0

        # Initialize the best seat and max distance
        max_dist = self.seats[0]  # Distance from seat 0
        best_seat = 0

        # Check distances between consecutive occupied seats
        for i in range(1, len(self.seats)):
            prev_seat = self.seats[i - 1]
            next_seat = self.seats[i]
            dist = (next_seat - prev_seat) // 2  # Midpoint distance

            if dist > max_dist:
                max_dist = dist
                best_seat = prev_seat + dist

        # Check distance from the last occupied seat to the last seat (n-1)
        if self.n - 1 - self.seats[-1] > max_dist:
            best_seat = self.n - 1

        # Insert the best seat while maintaining sorted order
        bisect.insort(self.seats, best_seat)
        return best_seat

    def leave(self, p: int) -> None:
        # Remove seat p from the list of occupied seats
        self.seats.remove(p)


#5. word search
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])
        
        def dfs(r, c, index):
            # Base case: if the current index is equal to word's length, we've found the word
            if index == len(word):
                return True
            # Check boundaries and if the character matches
            if r < 0 or r >= rows or c < 0 or c >= cols or board[r][c] != word[index]:
                return False
            
            # Mark the current cell as visited
            temp = board[r][c]
            board[r][c] = '#'
            
            # Explore all four possible directions
            found = (dfs(r + 1, c, index + 1) or  # down
                     dfs(r - 1, c, index + 1) or  # up
                     dfs(r, c + 1, index + 1) or  # right
                     dfs(r, c - 1, index + 1))    # left
            
            # Restore the cell's original value after the exploration
            board[r][c] = temp
            
            return found
        
        # Iterate through each cell in the board as the potential starting point
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == word[0] and dfs(r, c, 0):
                    return True
        
        return False
