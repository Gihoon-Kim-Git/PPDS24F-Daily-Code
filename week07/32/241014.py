class Solution:
    def getRow(self, rowIndex):
        if rowIndex == 0:
            return [1]
        elif rowIndex == 1:
            return [1, 1]
        else:
            previous = self.getRow(rowIndex - 1)
            current = [1]
            for i in range(1, len(previous)):
                current.append(previous[i] + previous[i - 1])
            current.append(1)
            return current