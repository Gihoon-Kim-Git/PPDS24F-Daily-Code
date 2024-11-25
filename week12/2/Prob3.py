from typing import List

class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        if not board or not board[0]:
            return 0
        
        rows, cols = len(board), len(board[0])
        count = 0
        
        for r in range(rows):
            for c in range(cols):
                # battleship의 top left에서 count를 수행, 나머지 위치에서는 X가 나오더라도 count하지 않음
                if board[r][c] == 'X':
                    if (r == 0 or board[r - 1][c] != 'X') and (c == 0 or board[r][c - 1] != 'X'):
                        count += 1
        
        return count