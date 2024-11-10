#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int row_index = 0;
        int col_index = col-1; 
        int cur = matrix[row_index][col_index];

        while(cur != target){
            if(row_index>=row || col_index<0){
                return false;
            }
            cur = matrix[row_index][col_index];
            if(cur < target){
                row_index++;
            }
            else{
                col_index--;
            }
        }
        return true;
    }
};


