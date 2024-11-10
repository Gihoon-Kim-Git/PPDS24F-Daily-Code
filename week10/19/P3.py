class Solution(object):
    def find(self, board, word, row, col):
        n_row = len(board)
        n_col = len(board[0])
        visited = [[False for _ in range(n_col)] for _ in range(n_row)]
        directions = [[-1, 0], [0, -1], [0, 1], [1, 0]]

        def find_util(v, w, i):
            if (i == len(word)-1):
                return True
            visited[v][w] = True
            for d in directions:
                if (0 <= v+d[0] < n_row and \
                    0 <= w+d[1] < n_col and \
                    not visited[v+d[0]][w+d[1]] and \
                    board[v+d[0]][w+d[1]] == word[i+1]):
                    if (find_util(v+d[0], w+d[1], i+1)): # 마지막 단어까지 찾으면 바로 종료
                        return True
            visited[v][w] = False # 백트래킹
            return False

        return find_util(row, col, 0)

    def exist(self, board, word):
        for i in range(len(board)):
            for j in range(len(board[0])):
                if (board[i][j] == word[0] and self.find(board, word, i, j)):
                    return True
        return False

if __name__ == "__main__":
    board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    result = Solution()
    print(result.exist(board, "ABCCED"))
    print(result.exist(board, "SEE"))
    print(result.exist(board, "ABCB"))
    board = [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
    print(result.exist(board, "ABCESEEEFS"))