"""Let's play the minesweeper game (Wikipedia, online game)!

You are given an m x n char matrix board representing the game board where:

'M' represents an unrevealed mine,
'E' represents an unrevealed empty square,
'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
'X' represents a revealed mine.
You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').

Return the board after revealing this position according to the following rules:
    1. If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
    2. If an empty square 'E' with no adjacent mines is reveal ed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
    3. If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
    4. Return the board when no more squares will be revealed. """

"""
m == board.length
n == board[i].length
1 <= m, n <= 50
board[i][j] is either 'M', 'E', 'B', or a digit from '1' to '8'.
click.length == 2
0 <= clickr < m
0 <= clickc < n
board[clickr][clickc] is either 'M' or 'E'."""

"""아이디어
    - Input인 2D array는 지금 '현재 지뢰판'이고,
    click은 누를 좌표(1개 자리)임.
    click 후에 2D array가 어떻게 바뀔지를 표현하는 문제임.
    - 지뢰판이 움직이는 방식 : 
        - 어느 한 점을 눌러서 개방하면 인접한 8방향이 다 개방됨.
        - 중단시점 : 'M'을 찾아서 'X'로 바뀌거나
                    더이상 연쇄적으로 reveal할 수 있는 좌표가 없거나
    - visit 되기 전은 M 또는 E
    - visit 되고 나면 B 또는 숫자(digit) 또는 X
        유의 : digit를 반환하려면 recursive안에 주변 지뢰 개수를 세는 logic이 필요할 듯 (만약 내 neighbor 중 지뢰가 있으면 count+=1)
    
    - recursive한 동작을 위해 DFS 사용
"""

"""수도코드
목표 : click에 주어진 좌표를 중단시점까지 dfs를 수행한 후 2D array의 상태 반환

1. dfs 함수 정의
    - input: board, 현재 좌표, 
    - return : 내 neighbor 중 지뢰 개수
    
    만약 현재 좌표가 이미 방문이 되었으면(B 또는 digit 또는 X) return 
    
    방문 전이라면(M 또는 E)
        현재좌표가 M이라면, return 1
    
        현재 좌표를 B 또는 digit 또는 X로 바꾸기
        m_count = 0
        현 좌표의 이웃들(8 방향)에 대해 방문
            - 만약 이웃좌표가 유효하다면(2D array 영역 안에 있다면)     
                cur_count = dfs(board, 이웃좌표)
                m_count += cur_count
        만약 m_count가 0이 아니라면
        현재 좌표 자리 값의 digit을 update
"""

class Solution(object):
    def updateBoard(self, board, click):
        rows, cols = len(board), len(board[0])
        directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        
        def count_adjacent_mines(r, c):
            count = 0
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] == 'M':
                    count += 1
            return count
        
        def dfs(r, c):
            if board[r][c] != 'E':
                return
            adjacent_mines = count_adjacent_mines(r, c)
            if adjacent_mines > 0:
                board[r][c] = str(adjacent_mines)
            else:
                board[r][c] = 'B'
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < cols:
                        dfs(nr, nc)
        
        click_row, click_col = click
        if board[click_row][click_col] == 'M':
            board[click_row][click_col] = 'X'
        else:
            dfs(click_row, click_col)
        
        return board