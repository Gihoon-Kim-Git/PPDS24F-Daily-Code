#😊
class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        row_idx = 0
        for i in range(m):
            if matrix[i][0] >= target:
                if matrix[i][0] == target : return True
                break
            else : row_idx += 1
        if row_idx == -1 : return False
        
        for j in range(row_idx): # index check!
            # Binary Search for each row
            left = 0
            right = n-1
            while left <= right:
                mid = (left+right)//2
                if matrix[j][mid] == target : return True
                elif matrix[j][mid] > target : right = mid-1
                else : left = mid+1

        return False

