# need to solve
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row, col = len(matrix), len(matrix[0])
        
        for i in range(row):
            if matrix[i][0] <= target and matrix[i][-1] >= target:
                low, high = 0, col

                while (low < high):
                    mid = (low + high) // 2
                    
                    if matrix[i][mid] == target:
                        return True
                    elif matrix[i][mid] < target:
                        low = mid + 1
                    else:
                        high = mid
                        
        return False