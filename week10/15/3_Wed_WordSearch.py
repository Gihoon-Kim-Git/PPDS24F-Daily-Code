class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        cols = len(board[0])
        rows = len(board)
        visited = set()
        
        def dfs(r, c, w):
            if w == len(word):
                return True
            if (r < 0 or c < 0 or r >= rows or c >= cols or (r,c) in visited or word[w] != board[r][c]):
                return False

            visited.add((r,c)) 

            result = (dfs(r+1, c, w+1) or dfs(r, c+1, w+1) or dfs(r-1, c, w+1) or dfs(r, c-1, w+1))
            
            visited.remove((r,c))

            return result
        
        for i in range(rows):
            for j in range(cols):
                    if dfs(i, j, 0):
                        return True
        return False 