from typing import List

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]
        elif rowIndex == 1:
            return [1,1]
        
        result = [1]
        pre = self.getRow(rowIndex - 1)
        for i in range(len(pre)-1):
            result.append(pre[i] + pre[i+1])
        result.append(1)
        return result