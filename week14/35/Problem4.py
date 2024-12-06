def updateBoard(board, click):
    rows, cols = len(board), len(board[0])

    def countMines(x, y):
        count = 0
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < rows and 0 <= ny < cols and board[nx][ny] == 'M':
                count += 1
        return count

    def dfs(x, y):
        if board[x][y] != 'E':
            return
        mine_count = countMines(x, y)
        if mine_count > 0:
            board[x][y] = str(mine_count)
        else:
            board[x][y] = 'B'
            for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < rows and 0 <= ny < cols:
                    dfs(nx, ny)

    x, y = click
    if board[x][y] == 'M':
        board[x][y] = 'X'
    else:
        dfs(x, y)
    
    return board
