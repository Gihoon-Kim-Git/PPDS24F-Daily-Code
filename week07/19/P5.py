class Solution1:
    def searchMatrix(self, matrix, target):
        if (matrix[0][0] > target):
            return False
        result = self.searchMatrixHelp(matrix, target, 0, 0, 0)
        if (result > 0):
            return True
        return False
    
    def searchMatrixHelp(self, matrix, target, i, j, a):
        if (matrix[i][j] > target):
            return a
        if (matrix[i][j] == target):
            return a+1
        if (matrix[i][j] < target):
            if (i+1 < len(matrix)):
                a = self.searchMatrixHelp(matrix, target, i+1, j, a)
            if (j+1 < len(matrix[0])):
                a = self.searchMatrixHelp(matrix, target, i, j+1, a)
        return a

class Solution2:
    def searchMatrix(self, matrix, target):
        if (matrix[0][0] > target):
            return False
        row = 0
        col = len(matrix[0]) - 1
        while (row < len(matrix) and col >= 0):
            if (matrix[row][col] == target):
                return True
            if (matrix[row][col] > target):
                col -= 1
            else:
                row += 1
        return False

if __name__ == "__main__":
    matrix = [[1,4,7,11,15],
              [2,5,8,12,19],
              [3,6,9,16,22],
              [10,13,14,17,24],
              [18,21,23,26,30]]
    result = Solution1()
    print(result.searchMatrix(matrix, 5))
    print(result.searchMatrix(matrix, 20))
    result = Solution2()
    print(result.searchMatrix(matrix, 5))
    print(result.searchMatrix(matrix, 20))