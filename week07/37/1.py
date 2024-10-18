class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        current_row = [1]  
        
        for i in range(rowIndex):
            next_row = [1]  
            
            for j in range(len(current_row) - 1):
                next_row.append(current_row[j] + current_row[j + 1])  
            
            next_row.append(1) 
            current_row = next_row  
        
        return current_row