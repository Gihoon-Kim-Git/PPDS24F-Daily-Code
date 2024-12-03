class Solution(object):
    def updateBoard(self, board, click):
        x, y = click
        if board[x][y] == "M":
            board[x][y] = "X"
        else:
            board = self.updateEmpty(board, x, y)
        return board
    
    def updateEmpty(self, board, x, y):
        if (board[x][y] != 'E'):
            return board
        n_row = len(board)
        n_col = len(board[0])
        directions = [[-1,-1],[-1,0],[-1,1],[0,-1],
                      [0,1],[1,-1],[1,0],[1,1]]
        for d in directions: # 폭탄이 근처에 있는 지 확인
            if (0 <= x+d[0] < n_row and \
                0 <= y+d[1] < n_col and \
                board[x+d[0]][y+d[1]] == 'M'):
                if (board[x][y] == 'E'):
                    board[x][y] = 1
                else:
                    board[x][y] += 1
        if (type(board[x][y]) == int): # 폭탄이 근처에 있으면 갯수를 표시하고 탐색 종료
            board[x][y] = str(board[x][y])
            return board
        else: # 폭탄이 근처에 없으면 'B'로 표시
            board[x][y] = 'B'
        for d in directions: # 근처가 'E'이면 탐색
            if (0 <= x+d[0] < n_row and \
                0 <= y+d[1] < n_col and \
                board[x+d[0]][y+d[1]] == 'E'):
                board = self.updateEmpty(board, x+d[0], y+d[1])
        return board

if __name__ == "__main__":
    result = Solution()
    board = [["E","E","E","E","E"],
             ["E","E","M","E","E"],
             ["E","E","E","E","E"],
             ["E","E","E","E","E"]]
    print(result.updateBoard(board, [3,0]))
    board = [["B","1","E","1","B"],
             ["B","1","M","1","B"],
             ["B","1","1","1","B"],
             ["B","B","B","B","B"]]
    print(result.updateBoard(board, [1,2]))
    board = [["E","E","E","E","E","E","E","E"],
             ["E","E","E","E","E","E","E","M"],
             ["E","E","M","E","E","E","E","E"],
             ["M","E","E","E","E","E","E","E"],
             ["E","E","E","E","E","E","E","E"],
             ["E","E","E","E","E","E","E","E"],
             ["E","E","E","E","E","E","E","E"],
             ["E","E","M","M","E","E","E","E"]]
    print(result.updateBoard(board, [0,0]))