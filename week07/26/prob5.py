class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:   
        m = len(matrix)
        n = len(matrix[0])
        i = m - 1
        j = 0

        while True:
            curr = matrix[i][j]
            if curr < target:
                if j + 1 < n:
                    j += 1
                else:
                    return False
            elif curr > target:
                if i - 1 >= 0:
                    i -= 1
                else:
                    return False
            else:
                return True