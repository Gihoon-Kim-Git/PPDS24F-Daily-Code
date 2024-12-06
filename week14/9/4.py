from typing import List

class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        n_row = len(board)
        n_col = len(board[0])

        directions = [
            [-1,-1], [-1,0], [-1,1],
            [0, -1],         [0, 1],
            [1, -1], [1, 0], [1, 1]]

        # click mine block
        if board[click[0]][click[1]] == 'M':
            board[click[0]][click[1]] = 'X'
            return board
        # click not mine block : board value is 'E'
        elif board[click[0]][click[1]] == 'E':
            # 주변에 mine이 존재하는지 확인
            mine_count = 0
            for di in directions:
                new_row, new_col = click[0]+di[0], click[1]+di[1]
                if (0 <= new_row < n_row) and (0 <= new_col < n_col) and board[new_row][new_col] == 'M':
                    mine_count += 1
            # mine이 없으면 blank 처리하고, 주변 값을 모두 click으로 처리
            if mine_count == 0:
                board[click[0]][click[1]] = 'B'
                for di in directions:
                    new_row, new_col = click[0]+di[0], click[1]+di[1]
                    if (0 <= new_row < n_row) and (0 <= new_col < n_col):
                        self.updateBoard(board, [new_row, new_col])
            else:
                board[click[0]][click[1]] = str(mine_count)
        # if block is already clicked
        return board

sol = Solution()
board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]
click = [3,0]
print(sol.updateBoard(board, click))
