#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) 
                return true;
            if (matrix[row][col] < target) 
                row++;
            else 
                col--;
        }
        return false;
    }
    
};