#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix[0][0] > target) return false;
        int row = 0, col = matrix[0].size()-1;
        while (row < matrix.size() and col >= 0) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};

    Solution result;
    cout << result.searchMatrix(matrix, 5) << endl;
    cout << result.searchMatrix(matrix, 20) << endl;

    return 0;
}