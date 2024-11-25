# week 12

# Wednesday. [Battleships in a Board](https://leetcode.com/problems/battleships-in-a-board/description/)

class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        count = 0
        
        for i, row in enumerate(board):
            for j, cell in enumerate(row):
                if cell == "X":
                    if (i == 0 or board[i - 1][j] == ".") and\
                       (j == 0 or board[i][j - 1] == "."):
                            count += 1
                            
        return count