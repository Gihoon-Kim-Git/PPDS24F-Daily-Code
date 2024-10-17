class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0, col = matrix[0].size()-1;
        while (col >= 0 && row <= matrix.size()-1) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                row++;
            } else {
                col--;
            }
        }
        return false;
    }
};