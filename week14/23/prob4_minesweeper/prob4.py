def update_board(board, click):
    """
    Simulate a Minesweeper game board update based on the player's click.
    """
    rows, cols = len(board), len(board[0])
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]

    def count_adjacent_mines(r, c):
        """Count the number of mines adjacent to the square (r, c)."""
        count = 0
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] == 'M':
                count += 1
        return count

    def dfs(r, c):
        """Perform DFS to reveal squares recursively."""
        if not (0 <= r < rows and 0 <= c < cols) or board[r][c] != 'E':
            return
        
        # Count adjacent mines
        mine_count = count_adjacent_mines(r, c)
        if mine_count > 0:
            board[r][c] = str(mine_count)
        else:
            board[r][c] = 'B'
            for dr, dc in directions:
                dfs(r + dr, c + dc)

    # Handle the initial click
    click_r, click_c = click
    if board[click_r][click_c] == 'M':
        board[click_r][click_c] = 'X'  # Game over
    else:
        dfs(click_r, click_c)

    return board

# Example usage:
board = [
    ['E', 'E', 'E', 'E', 'E'],
    ['E', 'E', 'M', 'E', 'E'],
    ['E', 'E', 'E', 'E', 'E'],
    ['E', 'E', 'E', 'E', 'E']
]
click = [3, 0]
updated_board = update_board(board, click)

updated_board
