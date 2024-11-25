from typing import List
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        visited = []
        direction = [[0,1],[0,-1],[-1,0],[1,0],[0,0]]
        m = len(board)
        n = len(board[0])
        # find X and make all the neighbors of it visited
        def helper(i:int,j:int) -> None :
            for dx,dy in direction:
                new_i = i+dx
                new_j = j+dy
                if 0<=new_i<m and 0<=new_j<n and board[new_i][new_j] == "X" and (new_i,new_j) not in visited:
                    visited.append((new_i,new_j))
                    helper(new_i,new_j)
        cnt = 0
        for i in range(m):
            for j in range(n):
                if board[i][j] == "X" and (i,j) not in visited:
                    cnt+=1
                    helper(i,j)
        return cnt