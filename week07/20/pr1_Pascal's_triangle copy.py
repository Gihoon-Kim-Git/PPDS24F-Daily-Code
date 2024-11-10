class Solution:
    def getRow(self, rowIndex: int) -> list[int]:
        if rowIndex == 0 : return [1]
        elif rowIndex == 1 : return [1,1]
        
        temp = self.getRow(rowIndex-1)
        ans = [1]*(rowIndex+1)
        for i in range(1,rowIndex):
            ans[i]=temp[i-1]+temp[i]
        
        return ans