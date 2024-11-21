def countBattleships(board):
    m, n = len(board), len(board[0])
    count = 0

    for i in range(m):
        for j in range(n):
            # Count only the top-left corner of each battleship
            if board[i][j] == 'X':
                if i > 0 and board[i-1][j] == 'X':  # Check above
                    continue
                if j > 0 and board[i][j-1] == 'X':  # Check left
                    continue
                count += 1
    return count

# Example usage
board = [
    ['X', '.', '.', 'X'],
    ['.', '.', '.', 'X'],
    ['.', '.', '.', 'X']
]
print(countBattleships(board))  # Output: 2
