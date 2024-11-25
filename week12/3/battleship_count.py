from typing import List

# function to check if cell is valid
def isValid(row, col, board: List[List[str]], visited: List[List[bool]]) -> bool:
	ROW = len(board)
	COL = len(board[0])
		
	# cell is out of bounds
	if (row < 0 or col < 0 or row >= ROW or col >= COL):
		return False
	
	# cell is not part of battleship or already visited
	if (board[row][col] == '.') or (visited[row][col]):
		return False

	# otherwise, it can be visited
	# cell is within bounds, part of battleship, and not already visited
	return True

# function to perform DFS: traversal on the matrix grid[]
def DFS_grid(row, col, board: List[List[str]], visited: List[List[bool]]) -> None:
    # Initialize direction vectors
    dRow = [0, 1, 0, -1]
    dCol = [-1, 0, 1, 0]
    
    # stack-based DFS implementation
    stack = []
	# push the starting cell into stack
    stack.append([row, col])

	# iterate until the stack is not empty
    while stack:
		# pop the top pair
        curr = stack.pop()
        row = curr[0]
        col = curr[1]

		# check if current cell is valid
        if not isValid(row, col, board, visited):
            continue
		
        # mark current cell as visited
        visited[row][col] = True

		# push all the adjacent cells (neighbors) onto stack
        for i in range(4):
            adjx = row + dRow[i]
            adjy = col + dCol[i]
            stack.append([adjx, adjy])

def countBattleships(board: List[List[str]]) -> int:
	
    # invalid board grid given as input
    if not board or not board[0]:
	    return 0
	
    # m x n matrix
    ROW = len(board) # m
    COL = len(board[0]) # n
	
    visited = [[False for _ in range(COL)] for _ in range(ROW)]
    battleship_cnt = 0
	
    for i in range(ROW):
        for j in range(COL):
			# cell is a battleship and not visited
            if board[i][j] == 'X' and not visited[i][j]:
			    # start new DFS traversal for a battleship
                DFS_grid(i, j, board, visited)
                battleship_cnt += 1
	
    return battleship_cnt

# example test case
board1 = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
board2 = [["."]]
print(countBattleships(board1)) # 2
print(countBattleships(board2)) # 0