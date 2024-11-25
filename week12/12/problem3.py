class Solution:
    def dfs(self,x,y, board):
        if(x>=len(board) or y>= len(board[0]) or board[x][y]=='.'):
            return
        board[x][y]='.'
        self.dfs(x+1,y,board)
        self.dfs(x,y+1,board)

    def countBattleships(self, board: List[List[str]]) -> int:
        m= len(board[0])
        n = len(board)
        cnt=0
        for i in range(n):
            for j in range(m):
                if board[i][j]=='X':
                    self.dfs(i,j,board)
                    cnt+=1
        return cnt
