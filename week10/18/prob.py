class Solution:
    #Problem 1: Guess Number Higher or Lower II
    def getMoneyAmount(self, n: int) -> int:
        # Initialize dp table with zero values
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        
        # Fill DP table by increasing interval length
        for length in range(2, n + 1):  # length of the interval
            for start in range(1, n - length + 2):  # start of the interval
                end = start + length - 1  # end of the interval
                dp[start][end] = float('inf')
                for k in range(start, end):
                    # Calculate cost for guessing 'k' as the first choice
                    cost = k + max(dp[start][k - 1], dp[k + 1][end])
                    # Minimize cost for interval [start, end]
                    dp[start][end] = min(dp[start][end], cost)
        
        # Minimum cost to guarantee a win from 1 to n
        return dp[1][n]

    #Problem 2: Stone Game IX
    def stoneGameIX(self, stones: list[int]) -> bool:
        # Count the number of stones with remainders 0, 1, and 2
        count = [0, 0, 0]
        for stone in stones:
            count[stone % 3] += 1
        
        # If there are no stones with remainders 1 or 2, Bob wins
        if count[1] == 0 and count[2] == 0:
            return False
        
        # If both remainder 1 and remainder 2 stones are available
        if count[0] % 2 == 0:
            # Alice can win if she balances between count[1] and count[2]
            return count[1] >= 1 and count[2] >= 1
        else:
            # With an odd count of remainder 0 stones, Alice's strategy changes
            return abs(count[1] - count[2]) > 2
    
    #Problem 3: Word Search
    def exist(self, board: list[list[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])
        
        def dfs(r, c, index):
            # If the entire word has been matched
            if index == len(word):
                return True
            
            # Check boundaries and if the cell matches the current character
            if r < 0 or c < 0 or r >= rows or c >= cols or board[r][c] != word[index]:
                return False
            
            # Temporarily mark the cell as visited
            temp = board[r][c]
            board[r][c] = "#"
            
            # Explore the four directions
            found = (dfs(r + 1, c, index + 1) or  # down
                     dfs(r - 1, c, index + 1) or  # up
                     dfs(r, c + 1, index + 1) or  # right
                     dfs(r, c - 1, index + 1))    # left
            
            # Restore the original value of the cell after exploration
            board[r][c] = temp
            return found
        
        # Start DFS from each cell
        for row in range(rows):
            for col in range(cols):
                if dfs(row, col, 0):  # If dfs returns True, word exists in the grid
                    return True
        return False
    
    #Problem 4: Exam Room
class ExamRoom:
    def __init__(self, n: int):
        self.n = n
        self.seats = []  # Keeps track of occupied seats in sorted order

    def seat(self) -> int:
        # If no seats are occupied, seat the first student at 0
        if not self.seats:
            seat = 0
            self.seats.append(seat)
            return seat

        # Evaluate the best seat for maximum distance
        max_dist = self.seats[0]
        seat = 0

        # Check distances between each pair of consecutive seats
        for i in range(1, len(self.seats)):
            prev_seat = self.seats[i - 1]
            next_seat = self.seats[i]
            # Calculate the distance from the middle point of the interval
            dist = (next_seat - prev_seat) // 2
            # Check if this midpoint offers a better distance
            if dist > max_dist:
                max_dist = dist
                seat = prev_seat + dist

        # Check distance from the last occupied seat to the end
        if (self.n - 1 - self.seats[-1]) > max_dist:
            seat = self.n - 1

        # Seat the student at the best position found
        self.seats.append(seat)
        self.seats.sort()  # Sort to maintain order after adding
        return seat

    def leave(self, p: int) -> None:
        # Remove the seat number from occupied seats
        self.seats.remove(p)
    
    #Problem 5: Minimum One Bit Operations

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