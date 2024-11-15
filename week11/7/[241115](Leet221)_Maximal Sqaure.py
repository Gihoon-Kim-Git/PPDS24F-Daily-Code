"""Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:
    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 4
    
Example 2:
    Input: matrix = [["0","1"],["1","0"]]
    Output: 1

Example 3:
    Input: matrix = [["0"]]
    Output: 0
"""

"""Constraints:
        m == matrix.length
        n == matrix[i].length
        1 <= m, n <= 300
        matrix[i][j] is '0' or '1'."""



###------------[정답코드 참고]
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        memo = [[0 for i in range(len(matrix[0]) + 1)] for i in range(len(matrix) + 1)]
        area = 0
        
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == '1':
                    memo[i+1][j+1] = min(memo[i][j+1], memo[i+1][j], memo[i][j]) + 1
                    area = max(area, memo[i+1][j+1])
                        
        return area*area



#%%
### [1] Naive APPROACH--------------------------------------------------------------------------------
"""아이디어
    한 변 크기 2 ~ min(m,n)를 조정해가면서 안의 요소들 검사하면서
    0이 나오면 return False

    답이 0이 되는 경우 : matrix안에 요소 '1'이 없는 경우
    답이 1이 되는 경우 : matrix안에 요소 '1'이 있는 경우
"""

        
"""수도코드
max_s = min(m,n)
count_one = 0

for s in range(max_s, 1, -1):
        start_row = 0
        end_row = n - s
        start_col = 0
        end_col = m - s
        for start_r in range(start_row, end_row+1):
            for start_c in range(start_col, end_col+1):
                if is_all_one(start_r, start_r + s-1, start_c, start_c + s - 1, matrix) == True:
                    return s*s

주어진 범위의 요소들이 전부 1인지 확인하는 함수
def is_all_one(row_start, row_end, col_start, col_end, matrix):
    for r in range(row_start, row_end+1):
        for c in range(col_start, col_end+1):
            if matrix[r][c] == 0:
                return False
    return True
"""



### 1) Naive하게 다 검사 : 76/80 (time limit exceeded)  한 변이 300일때 못 함.

def is_all_one(row_start, row_end, col_start, col_end, matrix):
    for r in range(row_start, row_end+1):
        for c in range(col_start, col_end+1):
            if matrix[r][c] == "0":
                return False
    return True

def maximalSquare(matrix):
    n = len(matrix)
    m = len(matrix[0])
    max_s = min(m,n)

    for s in range(max_s, -1, -1):
        start_row = 0
        end_row = n - s
        start_col = 0
        end_col = m - s
        for start_r in range(start_row, end_row+1):
            for start_c in range(start_col, end_col+1):
                #print(s, start_r,start_r + s-1, start_c, start_c + s-1)
                if is_all_one(start_r, start_r + s-1, start_c, start_c + s - 1, matrix) == True:
                    #print("x")
                    return s*s
                
                
matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
#matrix = [["0","1"],["1","0"]]
#matrix = [["0"]]
print(maximalSquare(matrix))



# %%
"""보다 효율적으로 돌릴 수 있는 방법은...??
    각 row별로 연속한 1의 개수를 산출해서 따로 list로 저장하는 건..?
"""


##
# %%
