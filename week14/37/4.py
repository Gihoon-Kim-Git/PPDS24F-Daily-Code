class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        def count_mines(r, c):
            count = 0
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < len(board) and 0 <= nc < len(board[0]) and board[nr][nc] == 'M':
                    count += 1
            return count

        def dfs(r, c):
            if board[r][c] != 'E':
                return
            mine_count = count_mines(r, c)
            if mine_count > 0:
                board[r][c] = str(mine_count)
            else:
                board[r][c] = 'B'
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < len(board) and 0 <= nc < len(board[0]):
                        dfs(nr, nc)

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]
        click_r, click_c = click
        
        if board[click_r][click_c] == 'M':
            board[click_r][click_c] = 'X'
        else:
            dfs(click_r, click_c)
        
        return board
