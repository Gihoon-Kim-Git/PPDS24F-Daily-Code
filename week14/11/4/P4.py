class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        dx = [1,1,1,0,0,-1,-1,-1]
        dy = [1,-1,0,1,-1,1,0,-1]
        x, y = click
        if board[x][y] == 'M':
            board[x][y] = 'X'
            return board
        
        count = 0
        if board[x][y] == 'E':
            for i in range(8):
                cx = x + dx[i]
                cy = y + dy[i]
                if valid(board,cx,cy) and board[cx][cy] == 'M':
                    count+=1

            if count == 0 :
                board[x][y] = 'B'
                for j in range(8):
                    cx = x + dx[j]
                    cy = y + dy[j]
                    if valid(board,cx,cy):
                        self.updateBoard(board, [cx, cy])
            else:
                board[x][y] = str(count)
            return board

def valid(board,x,y):
    return x < len(board) and y < len(board[0]) and x >= 0 and y >= 0