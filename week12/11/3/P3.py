#%%
class Solution:
    def countBattleships(self, board: list[list[str]]) -> int:
        count = 0
        r = len(board)
        c = len(board[0])
        visited = [[0] * c for _ in range(r)]
        

        def dft_help(i,j):
            if not visited[i][j]:
                visited[i][j] = 1
            dx = [-1,1,0,0]
            dy = [0,0,-1,1]

            for k in range(4):
                x = dx[k] + i
                y = dy[k] + j
                if valid(x,y) and board[x][y] == 'X' and not visited[x][y]:
                    dft_help(x,y)

        def valid(x,y):
            return x>=0 and y>=0 and x<r and y<c

        for i in range(r):
            for j in range(c):
                if board[i][j] == 'X' and not visited[i][j]:
                    count+=1
                    dft_help(i,j)

        return count



#%%
s = Solution()
board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
s.countBattleships(board)
# %%
