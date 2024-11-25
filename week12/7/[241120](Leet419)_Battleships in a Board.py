"""Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships)."""

"""아이디어
    : X로 만들 수 있는 island 개수를 구하자. 
        -island가 되려면, board[i][j] == 'X'여야 하고, 상-하, 좌-우에 'X'인 노드가 연결되어있을 수 있음. 
        - island 개수를 세는 때. 현재 위치에서 탐색하려는 다음위치가 a.모두 이미 방문되었거나 b. board[n_i][n_j] == '.'인 경우.
    : 유의. 이미 센 island 개수가 포함되지 않도록 유의.
"""

"""수도코드
목표 : 2차원 list안에서 상하좌우를 인접 노드 기준으로 보았을 때,island 수를 구하자.

1. visited list 초기화. board와 같은 모양으로.
    m = len(board)
    n = len(board[0])

2.탐색방향 정의
    dr = [1, -1, 0, 0]
    dc = [0, 0, 1, -1]
    
3.dfs 함수 정의 
    만약 (i,j)가 이미 방문되었으면 (visited[i][j] == 1):
        pass
    만약 (i,j)가 방문되지 않았으면 아래와 같이 방문처리 및 검사
        현재 자리 방문처리 : visited[i][j] = 1 : 
        만약 board[i][j] == 'X'일때 아래 수행.
            현재 위치의 상하좌우 방문 a.상하좌우 위치가 board 범위 내  b.아직 미방문상태일때
                a,b, 충족하는 상하좌우에서 dfs 수행
                
    ★섬 개수를 count하는 타이밍은? dfs가 끊겨서 outer loop 속에서 'X'부터 다시 dfs 시작할 때

4. island_count  초기화 
5.모든 board[i][j]를 방문하고 검사하면서, 아직 미방문된 'X' 만나면 island_count++ 하고 dfs 수행
    - for i in range(m)
        - for j in range(n)
            - IF board[i][j] == 'X' and visited[i][j] == 0:
            - dfs 함수 수행(i, j)
"""
#%%
class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """

        m = len(board)
        n = len(board[0])
        visited = [[0 for _ in range(n)] for _ in range(m) ]
        
        dr = [1, -1, 0, 0]
        dc = [0, 0, 1, -1]
        
        def dfs(i, j):
            if visited[i][j] == 0:
                visited[i][j] = 1
                if board[i][j] == 'X':
                    for d in range(4):
                        next_i = i+dr[d]
                        next_j = j+dc[d]
                        if 0<=next_i<m and 0<=next_j<n and visited[next_i][next_j] == 0:
                            dfs(next_i, next_j)
        
        island_count = 0
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'X' and visited[i][j] == 0 :
                    island_count += 1
                    dfs(i, j)
        
        return island_count
                    

board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
board = [["."]]
sol1 = Solution()
print(sol1.countBattleships(board))
# %% 같은 논리이지만 보다 간단하게 해결. (visited list 관리 대신에 방문한 곳은 "."로 값을 바꿔버림)
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        rows = len(board)
        cols = len(board[0])
        total = 0
        
        def dfs(r,c):
            if not (0 <= r < rows) or not (0 <= c < cols) or board[r][c] == ".":
                return 
            board[r][c] = "."
            dfs(r+1,c)
            dfs(r-1,c)
            dfs(r,c+1)
            dfs(r,c-1)

        for row in range(rows):
            for col in range(cols):
                if board[row][col] == "X":
                    total +=1
                    dfs(row,col)

        return total
            
            
        # since were traversing the board from left to right, top to bottom
        # we only need to consider what is below or to our right
        # we have already searched the other directions
