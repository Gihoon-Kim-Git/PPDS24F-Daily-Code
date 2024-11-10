class Solution:
    def getRow(self, rowIndex):
        result = [1] * (rowIndex + 1)
        if (rowIndex < 2):
            return result
        for i in range(1, len(result)-1):
            result[i] = self.getRow(rowIndex-1)[i-1] + self.getRow(rowIndex-1)[i]
        return result

if __name__ == "__main__":
    rowIndex = 5
    result = Solution()
    print(result.getRow(rowIndex))