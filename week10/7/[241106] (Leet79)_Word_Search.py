"""문제
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once."""

"""아이디어
    1. 일단 board에서 word[0]을 찾는다. (여러 개 있을 수 있음)
        찾은 경우에, 해당 자리에서부터 dfs를 진행한다. (dfs 방향은 상하좌우)
    2. dfs를 진행할 때 word[i]와 일치하면  다음 dfs를 하고, 일치하지 않으면 backtracking. (visit처리 복구)
    3. 만약 word[-1]까지 일치하면 true, 아니면 false.
"""

"""수도코드
input 
    board : 2차원 list
    word : 찾으려는 단어 list

output
    Return answer ( true or false)
    
함수 EXIST 정의
    -방문여부를 추적하는 visited 리스트 : board와 같은 모양. 0으로 초기화
    -방문방향 정의하는 directions : [(-1,0),(1,0),(0,-1),(0,1)]
    - DFS(curX,curY, word_index) -> bool 정의
        -- nonlocal word
        -- nonlocal board
        -- nonlocal directions
        -- IF word_index == len(word)-1 and word[word_index] == board[curY][curX] : #마지막 word[-1]까지 일치햇을 때, 다음 위치 방문 직후 return해서 종결되도록.
            RETURN True
        -- IF word[word_index] == board[curY][curX]:
            --- visited[curY][curX] 방문처리 : 0을 1로 바꾸기
            --- result를 False로 초기화, 상하좌우 다 돌았는데도 False이면 해당결과 반환
            --- 나의 상하좌우 좌표에 대한 DFS 실행
                : FOR dx, dy in directions
                    ---- newX = curX + dx
                    ---- newY = curY + dy
                    ---- IF newX,newY가 board범위 내에 있으면 & 아직 방문된 적이 없으면
                        ----- result = DFS(newX, newY, word_index+1)
                    ----- IF reuslt == FALSE : backtracking 필요함.
                        ------ newX,newY방문여부 수정 : 1을 0으로.
                    ----- If reulst == True :
                        ----- RETURN True
            ---- RETURN result
                        
        -- ELSE :
            --- RETURN False
    - answer 초기화 (false)
    - word[0]과 일치하는 좌표 찾아서 거기에서부터 DFS 실행
        : for i in range(len_n)
            for j in range(len_m)
                IF board[i][j] == word[0] :
                    if DFS(j, i, 0)== True :
                        answer = true
                        return answer
    - 다 순회했는데도 결과가 answer==false이면 
        -- return answer
    
"""

#%%
class Solution:
    def exist(self, board,  word: str) -> bool:
        len_m = len(board[0])
        len_n = len(board)
        visited = [[0 for _ in range(len_m)] for _ in range(len_n)]
        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        def DFS(curX, curY, word_index) :
            nonlocal word
            nonlocal board
            nonlocal directions
            #print(curX, curY, board[curY][curX], word[word_index])
            if word_index ==len(word)-1 and word[word_index] == board[curY][curX] :
                return True
            if word[word_index] == board[curY][curX] :         
                visited[curY][curX] = 1
                for dx,dy in directions:
                    newX = curX+dx
                    newY = curY+dy
                    if 0 <= newX <= len_m-1 and 0<=newY <= len_n-1 and visited[newY][newX] == 0:
                        sub_result = DFS(newX, newY, word_index+1)
                        print(f"sub_result:{sub_result}, new_X:{newX}, new_Y:{newY}, board[newY][newX]:{board[newY][newX]}, word:{word[word_index]}")
                        if sub_result : 
                            return True
                        else :
                            visited[newY][newX] = 0 
                #다 돌았는데도 result가 여전히 True를 반환하지 못했으면 False이므로 backtracking
                visited[curY][curX] = 0
                return False
                
            else : # board[curY][curX] != word[word_index]
                return False

        
        answer = False
        for i in range(len_n):
            for j in range(len_m):
                if board[i][j] == word[0]:
                    if DFS(j, i, 0) == True:
                        answer = True
                        return answer
        return answer



"""for dx, dy in directions 부분 다르게 구현한 코드 
class Solution:
    def exist(self, board, word: str) -> bool:
        len_m = len(board[0])
        len_n = len(board)
        visited = [[0 for _ in range(len_m)] for _ in range(len_n)]
        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        def DFS(curX, curY, word_index):
            nonlocal word
            nonlocal board
            nonlocal directions
            if word_index == len(word)-1 and word[word_index] == board[curY][curX]:
                return True
            if word[word_index] == board[curY][curX]:         
                visited[curY][curX] = 1
                for dx, dy in directions:
                    newX = curX + dx
                    newY = curY + dy
                    if 0 <= newX < len_m and 0 <= newY < len_n and visited[newY][newX] == 0:
                        if DFS(newX, newY, word_index + 1):
                            return True  # Return True immediately upon success
                visited[curY][curX] = 0  # Backtrack only if all directions fail
                return False  # Ensure a False is returned if all directions are explored and fail
            return False  # Return False if the character does not match
        
        for i in range(len_n):
            for j in range(len_m):
                if board[i][j] == word[0] and DFS(j, i, 0):
                    return True
        return False
"""

#board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]] 
#word = "SEE" #TRUE
#board = [["a"]]
#word = "a" #TRUE
board = [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
word = "ABCESEEEFS" #TRUE
sol1 = Solution()
print(sol1.exist(board, word))














#-[이전풀이]----------------------------------
"""class Solution(object):
    def exist(self, board, word):
        def dfs(board, i, j, word) :
            if len(word) == 0:
                return True

            if 0 <= i <len(board) and 0 <= j <len(board[0]) and board[i][j] == word[0] :

                temp_when_visited, board[i][j] = board[i][j], '0'
                if dfs(board, i+1, j, word[1:]) or dfs(board, i - 1, j , word[1:]) or dfs(board, i, j+1, word[1:]) or dfs(board, i, j-1, word[1:]):
                    return True

                board[i][j] = temp_when_visited

            return False

        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(board, i , j, word):
                    return True
            
        return False # 모든 곳에서 단어를 못 찾은 경우
"""
# %%
