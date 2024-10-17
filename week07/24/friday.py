# search a 2d matrix

from typing import List

class Solution:
    def find_recursive(self, matrix: List[List[int]], li, lj, ri, rj, target: int) -> bool:
        if li > ri or lj > rj:
            return False
        midi = (ri + li)//2
        midj = (rj + lj)//2
        found = False
        if matrix[midi][midj] == target:
            found = True
        elif matrix[midi][midj] > target:
            found = (
                self.find_recursive(matrix, li, lj, midi-1, midj-1, target)
                or self.find_recursive(matrix, li, midj, midi-1, rj, target)
                or self.find_recursive(matrix, midi, lj, ri, midj-1, target)
            )
        else:
            found = (
                self.find_recursive(matrix, midi+1, midj+1, ri, rj, target)
                or self.find_recursive(matrix, midi+1, lj, ri, midj, target)
                or self.find_recursive(matrix, li, midj+1, midi, rj, target)
            )
        return found
    
    def searchMatrix(self, mat: List[List[int]], target: int) -> bool:
        if not mat or not mat[0]:
            return False
        
        rows, cols = len(mat), len(mat[0])
        return self.find_recursive(mat,0,0,rows-1,cols-1,target)
