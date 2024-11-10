# This function checks if a given word exists in a 2D grid of characters.
# The word can be formed by sequentially adjacent cells (horizontally or vertically),
# and the same cell cannot be used more than once.
# We use Depth-First Search (DFS) to explore all possible paths in the grid to form the word.

def exist(board, word):
    # dimension of the grid: m(rows)*n(columns)
    m, n = len(board), len(board[0])

    # helper function: perform depth-first search (DFS) from a given cell
    def dfs(row, col, idx):

        # base case: if index reaches the length of the word, word found in grid
        if idx == len(word):
            return True
        
        # handle out-of-bounds cases, mismatched characters, and already visited cells
        # check if the current cell is 1. out of bounds or 2. the character doesn't match
        # or 3. if the cell has already been used (marked as visited)
        if row < 0 or row >= m or col < 0 or col >= n or board[row][col] != word[idx]:
            return False
        
        # temporarily mark current cell as visited
        temp = board[row][col] # save current cell character in temp for later use
        board[row][col] = '#' # prevents revisiting the same cell

        # perform DFS in all 4 directions: recursive call
        found = (
            dfs(row-1, col, idx+1) or # up
            dfs(row+1, col, idx+1) or # down
            dfs(row, col-1, idx+1) or # left
            dfs(row, col+1, idx+1)    # right
        )

        # after exploring all possible paths from the current cell, restore the original character
        board[row][col] = temp

        return found

    for r in range(m):
        for c in range(n):
            # if first character matches with the word, perform DFS
            # DFS result is True (word found)
            if board[r][c] == word[0] and dfs(r, c, 0):
                return True
    
    return False

# Example Usage
board1 = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word1 = "ABCB"
print(exist(board1, word1)) # False

board2 = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word2 = "ABCCED"
print(exist(board2, word2)) # True

# 0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week10 (main)
# $ python wordsearch_grid.py
# False
# True