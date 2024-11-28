# Battleships in a Board
from typing import List

class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        count = 0
        for i in range(len(board)):
            for j in range(len(board[0])):
                # Check if current cell is 'X' and no battleship above or to the left
                if board[i][j] == 'X':
                    if (i == 0 or board[i-1][j] != 'X') and (j == 0 or board[i][j-1] != 'X'):
                        count += 1
        return count