class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # start at top right corner
        row, col = 0, len(matrix[0]) - 1
        while(col > -1 and row < len(matrix)):
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                # if target is smaller than top right value, we can eliminate the last column
                # first value in the last column is the smallest value in that column
                col -= 1
            elif matrix[row][col] < target:
                # if target is larger that top right, we can eliminate the row
                # last value is the largest value in that row
                row += 1

        return False