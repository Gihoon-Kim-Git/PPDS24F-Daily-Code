# m x n grid의 character board가 주어졌을 때 
# board에서 인접한 character들로 word를 만들 수 있는가
# 단, 같은 위치의 character를 두 번 사용하는 것은 불가능 
"""
GPT 풀이 - DFT
"""
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])
        
        # Define the dfs function
        def dfs(r, c, i):
            # Base case: If the whole word is found
            if i == len(word):
                return True
            
            # Check bounds and if the current cell matches the character in word[i]
            if r < 0 or c < 0 or r >= rows or c >= cols or board[r][c] != word[i]:
                return False
            
            # Temporarily mark the cell as visited
            temp = board[r][c]
            board[r][c] = '#'
            
            # Explore in all four directions
            found = (dfs(r+1, c, i+1) or
                    dfs(r-1, c, i+1) or
                    dfs(r, c+1, i+1) or
                    dfs(r, c-1, i+1))
            
            # Restore the cell value
            board[r][c] = temp
            
            return found

        # Start the DFS from each cell
        for row in range(rows):
            for col in range(cols):
                if dfs(row, col, 0):  # Start DFS if the first letter matches
                    return True

        return False
