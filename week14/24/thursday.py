# Minesweeper

from typing import List

class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        # Get the row and column of the click
        i,j = click[0],click[1]
        
        # Base case: If the click is on a mine, change it to 'X' and return the board
        if board[i][j] == 'M':
            board[i][j] = 'X'
            return board
        
        # Get the dimensions of the board
        m,n = len(board),len(board[0])
        
        # Initialize a stack with the click position
        st = [(i,j)]
        
        # Define the directions for checking adjacent cells
        dirs = [(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]
        
        # While the stack is not empty
        while st:
            # Pop a cell from the stack
            x,y = st.pop()
            
            # If the cell is empty
            if board[x][y] == 'E':
                # Count the number of mines in adjacent cells
                cnt = 0
                for dx,dy in dirs:
                    new_x, new_y = x+dx, y+dy
                    if 0<=new_x<m and 0<=new_y<n and board[new_x][new_y] == 'M':
                        cnt += 1
                
                # If there are no mines in adjacent cells
                if cnt == 0:
                    # Change the cell to 'B'
                    board[x][y] = 'B'
                    
                    # Add all adjacent cells to the stack
                    for dx,dy in dirs:
                        new_x, new_y = x+dx, y+dy
                        if 0<=new_x<m and 0<=new_y<n:
                            st.append((new_x,new_y))
                else:
                    # Change the cell to the number of mines in adjacent cells
                    board[x][y] = str(cnt)
        
        # Return the updated board
        return board
    
if __name__ == "__main__":
    sol = Solution()
    print(sol.updateBoard([["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], [3,0]))
