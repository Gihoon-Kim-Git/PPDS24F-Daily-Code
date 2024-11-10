# Word Search
class Solution:
    def exist(self, board, word):
        def backtrack(i, j, k): # k is the index of the target word.
            # Base case
            if k == len(word): # if k is the last index of the target word, returns true.
                return True            
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] != word[k]:
                return False
            temp = board[i][j]
            board[i][j] = '' # empty to mark as visited

            if backtrack(i+1, j, k+1) or backtrack(i-1, j, k+1) or backtrack(i, j+1, k) or backtrack(i, j-1, k):
                return True
            # in case if not found, return the board value.
            board[i][j] = temp
            return False
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if backtrack(i, j, 0):
                    return True
        return False