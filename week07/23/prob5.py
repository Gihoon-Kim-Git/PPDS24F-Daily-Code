class Solution:
    def searchMatrix(self, mat, target: int):
        
        m=len(mat)
        n=len(mat[0])
        
        i=m-1
        j=0
        
        while i>=0 and j<n:
            if mat[i][j]==target:
                return True
            elif mat[i][j]<target:
                j+=1
            else:
                i-=1
                
        return False