class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row_num = len(matrix)
        row_col = len(matrix[0])

        r = row_num - 1
        c = 0
        while r >= 0 and c < row_col:
            if target == matrix[r][c]:
                return True
            elif target < matrix[r][c]:
                r -= 1
            else:
                c += 1
        
        return False