from collections import List

class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:

        cnt = 0
        for i, row in enumerate(board):
            for j, cell in enumerate(row):
                if cell == "X":
                    if (i == 0 or board[i - 1][j] == ".") and (j == 0 or board[i][j-1] == "."):
                        cnt += 1
        return cnt