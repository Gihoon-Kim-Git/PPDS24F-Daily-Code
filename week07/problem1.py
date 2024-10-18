class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        mp= [[1],[1,1]]
        if rowIndex<2:
            return mp[rowIndex]
        for i in range(1,rowIndex):
            curr=[1]
            for ele in range(0,len(mp[i])-1):
                curr.append(mp[i][ele]+ mp[i][ele+1])
            curr.append(1)
            mp.append(curr)
        return mp[rowIndex]



        