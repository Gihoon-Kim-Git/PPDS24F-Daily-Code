"""
<Word Search>

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
"""

def get_neighbors(board, row, col):
    neighbors = []
    if row-1 >= 0:
        neighbors.append((row-1,col))
    if row+1 < len(board):
        neighbors.append((row+1,col))
    if col-1 >= 0:
        neighbors.append((row,col-1))
    if col+1 < len(board[0]):
        neighbors.append((row, col+1))
    return neighbors


def exist(board, word):

    def dfs(row,col,word_idx,visited):

        if word_idx == len(word):   # 찾으려는 단어 다 찾음
            return True
        
        neighbors = get_neighbors(board, row, col)

        for new_x, new_y in neighbors: 
            if board[new_x][new_y] == word[word_idx] and ((new_x,new_y) not in visited):    # 다음 단어 찾음
                visited.append((new_x,new_y))
                if dfs(new_x,new_y,word_idx+1,visited): 
                    return True
                visited.pop()  # new_x,new_y를 기준으로 경로 탐색 시도했다 실패하면 new_x,new_y 말고 다른 길 시도

        return False  # 모든 이웃에서 단어 찾지 못함
    

    for row in range(len(board)):
        for col in range(len(board[row])):
            if board[row][col] == word[0]:     # 여러 시작 후보
                if dfs(row,col,1,[(row,col)]):
                    return True
    return False



# board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
# word = "ABCCED"
# board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
# word = "SEE"

# board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
# word = "ABCB"

board = [["C","A","A"],["A","A","A"],["B","C","D"]]   # true
word = "AAB"

print(exist(board,word))

