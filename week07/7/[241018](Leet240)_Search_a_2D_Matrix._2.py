"""<문제>
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
"""
"""<constraint>
    m == matrix.length
    n == matrix[i].length
    1 <= n, m <= 300
    -109 <= matrix[i][j] <= 109
    All the integers in each row are sorted in ascending order.
    All the integers in each column are sorted in ascending order.
    -109 <= target <= 109
"""
# """문제풀이전략
#     1. Divide and conquer처럼 접근하면 되지 않을까!?
#         중간을 기준으로 4분할. 4개 영역 중에 탐색할 가치가 있는 부분에 들어가서 탐색하면 됨.
#       - 중간 열 : mid_col에서 시작해서 위->아래로 이동하며 target보다 큰 첫번째 행을 찾음/ 이 행을 기준으로, 다음 탐색할 좌측 상단, 우측 하단 영역을 결정.
#     2. Divide : LeftTop, RightTop, LeftBottom, RightBottom
#            LeftTop: 시작점부터 (mid_row - 1, mid_col - 1)까지
#            RightBottom: (mid_row, mid_col)부터 마지막 점까지
#            LeftBottom: (mid_row, 0)부터 (끝, mid_col - 1)까지
#            RightTop: (0, mid_col)부터 (mid_row - 1, 끝)까지
#     3. 재귀 탐색 :
#           가능성있는 영역에 대해 재귀적으로 탐색
#     4. 종료조건:
#           타겟값 찾으면 True반환
#           검색범위를 탐색한 후에도 타겟값 못 찾으면 False 반환"""

"""문제풀이1)
    1. row 단위로 검사.각 row에서 binary search해서 target이 있으면 true를 반환. 없으면 다음 row 검사.
"""

#풀이1)
def binary_search(arr, start, end, target):
    i = start
    j = end
    
    while i <= j :
        mid = (i+j) // 2
        if arr[mid] == target :
            return True
        elif arr[mid] > target:
            j = mid-1
        else :
            i = mid+1
    return False

class Solution:
    def searchMatrix(self, matrix, target):
        len_m = len(matrix)
        len_n = len(matrix[0])
        
        for row in matrix:
            if binary_search(row, 0, len_n-1,target) == True :
                return True
            
        return False 

    
##---------------<Greedy> : Stepwise 탐색방법 ( O(M+N))
def searchMatrix(matrix,  target: int) -> bool:

    if not matrix or not matrix[0]:
        return False
    
    # 행(row)의 개수와 열(column)의 개수를 구함
    m = len(matrix)
    n = len(matrix[0])
    
    # 왼쪽 아래 코너에서 시작
    row = m - 1
    col = 0
    
    # 행렬 내에서 범위를 벗어나지 않을 때까지 반복
    while row >= 0 and col < n:
        if matrix[row][col] == target:
            return True  # 값을 찾은 경우
        elif matrix[row][col] > target:
            row -= 1  # 현재 값이 target보다 크므로 위쪽으로 이동
        else:
            col += 1  # 현재 값이 target보다 작으므로 오른쪽으로 이동
    
    return False  # 값을 찾지 못한 경우



###---------- 4분할로 나눠서 진행하는 방법. (divide and conquer?)
    
def searchMatrix(matrix, target):
    if not matrix or not matrix[0]:
        return False
    
    def search_sub(left, up, right, down):
        # 서브행렬이 더이상 존재하지 않는 경우
        if left > right or up > down : 
            return False
        
        # 타겟이 서브행렬 범위 밖에 있는 경우
        elif target < matrix[up][left] or target > matrix[down][right] :
            return False
        
        mid = left + (right - left) // 2
        
        #중간 열에서 타겟을 찾거나, 더 작은 행을 찾기
        row = up
        while row <= down and matrix[row][mid] <= target:
            if matrix[row][mid] == target:
                return True
            row +=1
        
        #타겟이 중간 열의 값보다 작은 경우, 좌측하단과 우측 상단 탐색
        return search_sub(left, row, mid-1, down) or search_sub(mid+1, up, right, row-1)
        
    #전체 행렬에 대해 탐색 시작
    return search_sub(0,0, len(matrix[0])-1, len(matrix) - 1)