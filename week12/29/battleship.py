"""
<Battleships in a Board>

Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).
"""

def countBattleships(board):
    if not board:
        return 0

    m, n = len(board), len(board[0])
    count = 0

    for i in range(m):
        for j in range(n):
            if board[i][j] == 'X':
                if i > 0 and board[i-1][j] == 'X':  # Check above
                    continue
                if j > 0 and board[i][j-1] == 'X':  # Check left
                    continue
                count += 1

    return count

board = [
    ['X', '.', '.', 'X'],
    ['.', '.', '.', 'X'],
    ['.', '.', '.', 'X']
]
print(countBattleships(board))  # 2
