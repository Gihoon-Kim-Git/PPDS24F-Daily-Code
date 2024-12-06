class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        # Dimensions of the board
        m, n = len(board), len(board[0])
        
        # Directions for moving to adjacent cells (8 possible moves)
        directions = [
            (-1, -1), (-1, 0), (-1, 1),
            (0, -1),         (0, 1),
            (1, -1), (1, 0), (1, 1)
        ]
        
        def countMines(x, y):
            """Count the number of adjacent mines around (x, y)."""
            count = 0
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and board[nx][ny] == 'M':
                    count += 1
            return count
        
        def dfs(x, y):
            """Perform DFS to reveal cells starting from (x, y)."""
            # Count adjacent mines
            mine_count = countMines(x, y)
            if mine_count > 0:
                # If there are adjacent mines, reveal the number and stop
                board[x][y] = str(mine_count)
            else:
                # If no adjacent mines, reveal as 'B' and explore neighbors
                board[x][y] = 'B'
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and board[nx][ny] == 'E':
                        dfs(nx, ny)
        
        # Get the click position
        click_row, click_col = click
        
        # Rule 1: Clicked a mine
        if board[click_row][click_col] == 'M':
            board[click_row][click_col] = 'X'
        else:
            # Rule 2 and 3: Clicked an empty square
            dfs(click_row, click_col)
        
        return board
