class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        strength = []
        
        for i, row in enumerate(mat):
            # Count the number of soldiers (1's) in the row
            num_soldiers = sum(row)
            # Append (num_soldiers, row_index) to the list
            strength.append((num_soldiers, i))
        
        # Sort the list by number_of_soldiers, then by row index
        strength.sort(key=lambda x: (x[0], x[1]))
        
        # Extract the indices of the first k rows
        return [index for _, index in strength[:k]]