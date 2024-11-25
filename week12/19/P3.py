class Solution(object):
    def countBattleships(self, board):
        n_row = len(board)
        n_col = len(board[0])
        visited = [[False for _ in range(n_col)] for _ in range(n_row)]
        
        def dfs_util(v, w):
            visited[v][w] = True
            if (0 <= v-1 < n_row and 0 <= w < n_col and \
                not visited[v-1][w] and board[v-1][w] == "X"):
                dfs_util(v-1, w)
            if (0 <= v+1 < n_row and 0 <= w < n_col and \
                not visited[v+1][w] and board[v+1][w] == "X"):
                dfs_util(v+1, w)
            if (0 <= v < n_row and 0 <= w-1 < n_col and \
                not visited[v][w-1] and board[v][w-1] == "X"):
                dfs_util(v, w-1)
            if (0 <= v < n_row and 0 <= w+1 < n_col and \
                not visited[v][w+1] and board[v][w+1] == "X"):
                dfs_util(v, w+1)

        cnt = 0
        for i in range(n_row):
            for j in range(n_col):
                if not visited[i][j] and board[i][j] == "X":
                    dfs_util(i, j)
                    cnt += 1        

        return cnt

if __name__ == "__main__":
    result = Solution()
    board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
    print(result.countBattleships(board))
    board = [["."]]
    print(result.countBattleships(board))