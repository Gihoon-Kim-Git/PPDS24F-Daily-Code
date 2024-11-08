class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        direction = {(1,0), (0,1), (-1,0), (0,-1)}

        def dfs(board, visited, word, r, c):
            if not word:
                return True
            print(word)
            visited[r][c] = True
            for dr, dc in direction:
                nr = r + dr
                nc = c + dc

                if 0 <= nr < row and 0 <= nc < col:
                    if board[nr][nc] == word[0] and visited[nr][nc] == False:
                        if dfs(board, visited, word[1:], nr, nc):
                            return True

            visited[r][c] = False ## 백트래킹!!
            return False

        row = len(board)
        col = len(board[0])
        for i in range(row):
            for j in range(col):
                visited = [[False for _ in range(col)] for _ in range(row)]
                if not visited[i][j]:
                    if board[i][j] == word[0]:
                        visited[i][j] = True
                        if dfs(board, visited, word[1:], i, j):
                            return True

        return False