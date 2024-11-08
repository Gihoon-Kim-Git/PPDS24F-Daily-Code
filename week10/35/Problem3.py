# leetcode 79. Word Search
def exist(board, word):
    rows, cols = len(board), len(board[0])
    path = set()

    def backtrack(r, c, i):
        if i == len(word):
            return True
        if (r < 0 or c < 0 or r >= rows or c >= cols or
            word[i] != board[r][c] or (r, c) in path):
            return False

        path.add((r, c))
        res = (backtrack(r + 1, c, i + 1) or
               backtrack(r - 1, c, i + 1) or
               backtrack(r, c + 1, i + 1) or
               backtrack(r, c - 1, i + 1))
        path.remove((r, c))
        return res

    for r in range(rows):
        for c in range(cols):
            if backtrack(r, c, 0):
                return True
    return False
