from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n_col = len(board[0])
        n_row = len(board)
        N = len(word)

        def find_next(row, col, index):
            if index == N:
                return True
            if row < 0 or row >= n_row or col < 0 or col >= n_col or board[row][col] != word[index]:
                return False

            # 임시로 값을 변경(추후 원복)
            temp = board[row][col]
            board[row][col] = '#'

            directions = [(-1,0), (1,0), (0,-1), (0,1)]
            for dr, dc in directions:
                if find_next(row+dr, col+dc, index+1):
                    return True

            # 상태 원복(backtracking)
            board[row][col] = temp

            return False
        
        for i in range(n_row):
            for j in range(n_col):
                if board[i][j] == word[0]:
                    # 첫 글자가 일치하는 경우 탐색을 시작
                    if find_next(i, j, 0):
                        return True
        
        return False  

                    
sol = Solution()
"""
board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word = "ABCCED"
"""

board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word = "SEE"
"""
board = [["a"]]
word = "a"
"""
"""
board = [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
word = "ABCESEEEFS"
"""
"""
# false
board = [["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","B"],["A","A","A","A","B","A"]]
word = "AAAAAAAAAAAAABB"
"""
print(sol.exist(board, word))
