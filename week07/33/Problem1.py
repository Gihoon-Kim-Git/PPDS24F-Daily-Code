# 파스칼의 삼각형

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]
        else:
            lst = [1]
            prev = self.getRow(rowIndex-1)
            for i in range(rowIndex-1):
                lst.append(prev[i]+prev[i+1])
            lst.append(1)
            return lst
