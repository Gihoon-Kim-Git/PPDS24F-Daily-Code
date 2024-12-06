from collections import deque
from typing import List
# q = deque()
# q.append([1,3])
# q.append([4,3])
# # print(q.pop())
# # print(q)
# # print(q.pop())
# print([1,3] in q)
# print([1,23] in q)
# while q:
#     x,y = q.pop()
#     print(x,y)
class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        # Click only one time
        m = len(board)
        n = len(board[0])
        # M : unrevealed mine / E : unrevealed Empty space / Click -> M or E
        # B : revealed blank space with No adjanced mine / 1~8 : revealed with num of adjacent mine
        # X -> reveald mine : game set
        direction = [[0,1],[0,-1],[1,0],[1,1],[1,-1],[-1,0],[-1,1],[-1,-1]] # 8ea
        q = deque()
        q.append(click)
        while q :
            y,x = q.pop()
            # if click mine( click M )
            if board[y][x] == 'M':
                board[y][x] = 'X'
                break
            # if click 'E' at first time
            else:
                cnt = 0
                for i,j in direction:
                    dy = y + j
                    dx = x + i
                    # Check mine for curr status
                    if 0<=dy<m and 0<=dx<n and board[dy][dx] == 'M':
                        cnt+=1
                # Curr node is 'E' add adjacent node to queue
                if cnt==0 :
                    board[y][x] = 'B'
                    for i,j in direction:
                        dy = y + j
                        dx = x + i
                        if 0<=dy<m and 0<=dx<n and board[dy][dx] == 'E':
                            q.append([dy,dx])
                # Curr node is 'Number'
                else : board[y][x] = str(cnt)   
             
        return board
                