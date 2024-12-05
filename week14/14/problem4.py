# week 14

# Thursday. [Minesweeper](https://leetcode.com/problems/minesweeper/description/)

class Solution:
    def updateBoard(self, board, click):

        if board[click[0]][click[1]] == 'M':                # <-- handle case that
            board[click[0]][click[1]] = 'X' ; return board  #     click is mined

        adjacent = lambda x,y : [(x+dx,y+dy) for dx in range(-1,2) for dy in range(-1,2) 
                if (dx or dy) and 0 <= x+dx < len(board) and 0 <= y+dy < len(board[0])]
        
        def dfs(x: int,y: int)-> None:                      # –––––––––start function–––––––––
            adj = adjacent(x,y)
                                                            
            mines = sum(board[X][Y] == 'M' for X,Y in adj)  # <-- count up adjacent mines 
                                                            #     to board[x][y]
            if  mines:
                board[x][y] = str(mines)                    # <-- If mines, write count...

            else:    
                board[x][y] = 'B'                           # <-- ... if not, mark it "revealed" 

                for X,Y in adj:
                    if board[X][Y] == 'E':                  # <-- explore each adjacent cell
                        dfs(X,Y)                            #     if unexplored
            return                                          #––––––––––end function––––––––––
                                                            
        dfs(*click)                                         # <-- start at click

        return board                                        # <-- return updated board