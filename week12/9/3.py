def dfs(i, j, visited, board, cnt):
    visited[i][j] = True

    if (j+1 < len(board[0])) and (0 <= i) and (i < len(board)):
        if board[i][j+1] == 'X' and visited[i][j+1] == False:
            dfs(i, j+1, visited, board, cnt)

    if (j > 0) and (0 <= i) and (i < len(board)):
        if board[i][j-1] == 'X' and visited[i][j-1] == False:
            dfs(i, j+1, visited, board, cnt)
    
    if (i+1 < len(board)) and (0 <= j) and (j < len(board[i])):
        if board[i+1][j] == 'X' and visited[i+1][j] == False:
            dfs(i+1, j, visited, board, cnt)
    
    if (i > 0) and (0 <= j) and (j < len(board[i])):
        if board[i-1][j] == 'X' and visited[i-1][j] == False:
            dfs(i-1, j, visited, board, cnt)
            
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        visited = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
        cnt = [0]
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'X' and visited[i][j] == False:
                    dfs(i, j, visited, board, cnt[0])
                    cnt[0] += 1
        
        return cnt[0]

