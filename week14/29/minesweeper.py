"""
<Minesweeper>
"""

def update_board(board, click):
    rows, cols = len(board), len(board[0])
    directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
    
    def count_adjacent_mines(r, c):
        count = 0
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] == 'M':
                count += 1
        return count

    def dfs(r, c):
        if not (0 <= r < rows and 0 <= c < cols) or board[r][c] != 'E':
            return
        adjacent_mines = count_adjacent_mines(r, c)
        if adjacent_mines > 0:
            board[r][c] = str(adjacent_mines)
        else:
            board[r][c] = 'B'
            for dr, dc in directions:
                dfs(r + dr, c + dc)
    
    clickr, clickc = click
    if board[clickr][clickc] == 'M':
        board[clickr][clickc] = 'X'  # Game over
    else:
        dfs(clickr, clickc)
    
    return board

# Example usage:
board = [
    ["E", "E", "E", "E", "E"],
    ["E", "E", "M", "E", "E"],
    ["E", "E", "E", "E", "E"],
    ["E", "E", "E", "E", "E"]
]
click = [3, 0]

updated_board = update_board(board, click)
for row in updated_board:
    print(row)
