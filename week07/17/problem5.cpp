// week 07

// Friday. [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix-ii/description/)

// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
 

// Example 1:


// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true
// Example 2:


// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false


#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // 왼쪽 밑에서 시작
        // target보다 작으면 위로 올라감
        // target보다 크면 오른쪽으로 감

        int m = matrix.size()-1;
        int n = 0;

        while (m >= 0 && n < matrix[0].size()){
            if (matrix[m][n] == target){
                return true;
            }
            else if (matrix[m][n] > target){
                m--;
            }
            else{
                n++;
            }
        }
        

        return false;
    
    }

};