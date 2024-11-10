/*<문제>
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

<constraint>
    m == matrix.length
    n == matrix[i].length
    1 <= n, m <= 300
    -109 <= matrix[i][j] <= 109
    All the integers in each row are sorted in ascending order.
    All the integers in each column are sorted in ascending order.
    -109 <= target <= 109
*/

/*풀이 
    1. serach_sub(left, up, right, down)
        #서브행렬이 더이상 존재하지 않는 경우 : return False
        #타겟이 서브행렬 범위 밖에 있는 경우 : return False
        #그외
            # mid_col 확인을 위한 col_mid값 조정
            # up, down 사이의 row 중에 mid_col값이 target과 같은 것이 있거나 더 작은지 확인
            # 
            */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchSub(std::vector<std::vector<int>>& matrix, int target, int left, int right, int up, int down) {
        // 유효 범위를 벗어났는지 확인
        if (left > right || up > down) {
            return false;
        }
        
        // 타겟이 검색 범위를 벗어난 경우
        if (target < matrix[up][left] || target > matrix[down][right]) {
            return false;
        }

        // 중간 열 인덱스 계산
        int mid_col = left + (right - left) / 2;

        // 중간 열을 스캔하여 타겟 찾기
        int i = up;
        while (i <= down && matrix[i][mid_col] <= target) {
            if (matrix[i][mid_col] == target) {
                return true;
            }
            i++;
        }

        // 타겟이 발견되지 않으면 두 부분으로 나누어서 다시 탐색
        return searchSub(matrix, target, left, mid_col - 1, i, down) || searchSub(matrix, target, mid_col + 1, right, up, i - 1);
    }

    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        return searchSub(matrix, target, 0, cols - 1, 0, rows - 1);
    }
};
