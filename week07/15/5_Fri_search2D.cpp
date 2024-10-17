#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_num = matrix.size();
        int col_num = matrix[0].size();

        int r = row_num - 1;
        int c = 0;

        while (r >= 0 && c < col_num) {
            if (target == matrix[r][c]) return true;
            else if (target < matrix[r][c]) r--;
            else c++;            
        } 
        return false;
    }
};