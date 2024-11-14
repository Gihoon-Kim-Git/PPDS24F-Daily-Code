#include <vector>
// #include <iostream>
#include <algorithm>
using namespace std;

// top-down recursion : time limit exceeded

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();

        vector<vector<char>> maxAreas(M, vector<char>(N, -1));
        int max_len = -1;
        int curr_len;
        for (size_t i=0; i<M; i++) {
            for (size_t j=0; j<N; j++) {
                // cout << "outer loop : " << i << " " << j << endl;
                curr_len = helper(matrix, maxAreas, i, j);
                if (curr_len > max_len) max_len = curr_len;
            }
        }

        return max_len * max_len;
    }

    // mat(i, j) 를 왼쪽 위 꼭지점으로 하여 만들 수 있는 가장 큰 square 의 한 변 길이
    int helper(const vector<vector<char>>& matrix, vector<vector<char>>& area, int i, int j) {
        // cout << "helper called : " << i+1 << " " << j+1 << endl;
        // 기록이 안 되어있는 경우
        if (area[i][j] < 0) {
            // base case 1 : 오른쪽 끝 또는 아래쪽 끝
            if (i == matrix.size() - 1 || j == matrix[0].size() - 1) {
                if (matrix[i][j] == '0') area[i][j] = 0;
                else area[i][j] = 1;
            }
            // base case 2 : "0"
            else if (matrix[i][j] == '0') area[i][j] = 0;
            // recursive case : 그 외
            else {
                int a = helper(matrix, area, i+1, j);
                int b = helper(matrix, area, i, j+1);
                int c = helper(matrix, area, i+1, j+1);
                area[i][j] = 1 + min({a, b, c});
            }
        }
        return area[i][j];
    }
};
