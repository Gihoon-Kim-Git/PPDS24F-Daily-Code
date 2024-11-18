class Solution1(object):
    def maximalSquare(self, matrix):
        n_row = len(matrix)
        n_col = len(matrix[0])

        answer = 0
        for i in range(n_row):
            for j in range(n_col):
                if (matrix[i][j] == "1"):
                    temp = self.checkSquare(matrix, i, j, n_row, n_col)
                    answer = max(answer, temp)
        return answer
    
    def checkSquare(self, matrix, i, j, n_row, n_col):
        scale = 0
        while (i+scale<n_row and j+scale<n_col):
            squareSum = 0
            for r in range(i, i+scale+1):
                for c in range(j, j+scale+1):
                    squareSum += int(matrix[r][c])
            if (squareSum < (scale+1)**2):
                break
            scale += 1
        return scale**2

class Solution2(object):
    def maximalSquare(self, matrix):
        n_row = len(matrix)
        n_col = len(matrix[0])

        squareMax = 0
        for i in range(1, n_row):
            for j in range(1, n_col):
                if (matrix[i][j] == '1'):
                    squareMin = min(int(matrix[i-1][j]), int(matrix[i][j-1]), int(matrix[i-1][j-1]))
                    if (squareMin > 0):
                        matrix[i][j] = squareMin + 1
                    squareMax = max(squareMax, int(matrix[i][j]))

        for i in range(0, n_row):
            squareMax = max(squareMax, int(matrix[i][0]))
        for j in range(0, n_col):
            squareMax = max(squareMax, int(matrix[0][j]))

        return squareMax**2

if __name__ == "__main__":
    # result = Solution1()
    result = Solution2()
    matrix = [["1","0","1","0","0"],
              ["1","0","1","1","1"],
              ["1","1","1","1","1"],
              ["1","0","0","1","0"]]
    print(result.maximalSquare(matrix))
    matrix = [["0","1"],
              ["1","0"]]
    print(result.maximalSquare(matrix))
    matrix = [["0"]]
    print(result.maximalSquare(matrix))
    matrix = [["1","1","1","1","1"],
              ["1","1","1","1","1"],
              ["0","0","0","0","0"],
              ["1","1","1","1","1"],
              ["1","1","1","1","1"]]
    print(result.maximalSquare(matrix))
    matrix = [["1","1","1","1","0"],
              ["1","1","1","1","0"],
              ["1","1","1","1","1"],
              ["1","1","1","1","1"],
              ["0","0","1","1","1"]]
    print(result.maximalSquare(matrix))