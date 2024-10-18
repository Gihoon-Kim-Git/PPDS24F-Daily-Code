#include <vector>
using namespace std;
#define OVERFLOW 1000000001

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return helper(matrix, target, 0, 0);
    }

    // matrix[i:, j:] 에 target 이 있을 수 있는 지 검사
    bool helper(vector<vector<int>>& matrix, int target, int i, int j) {
        // base case
        // - out of index
        if (i >= matrix.size() || j >= matrix[0].size()) return false;
        // - 가능성 없음 or visited
        else if (matrix[i][j] > target) return false;
        // - 찾음
        else if (matrix[i][j] == target) return true;

        // recursive case
        else {
            matrix[i][j] = OVERFLOW;        // visited
            // int i_inf = i+1;
            // int j_inf = j+1;
            return
                // helper(matrix, target, i+1, j+1) || 
                // helper(matrix, target, i_inf, j) ||
                // helper(matrix, target, i, j_inf);
                helper(matrix, target, i+1, j) ||
                helper(matrix, target, i, j+1);
        }
    }
};