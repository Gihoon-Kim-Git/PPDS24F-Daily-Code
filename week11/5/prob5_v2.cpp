#include <vector>
#include <algorithm>
using namespace std;

// bottom-up iterative : accepted

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // bottom up

        int M = matrix.size();
        int N = matrix[0].size();

        int max_len = 0;

        // table[i,j] : [i, j] 를 오른쪽 아래 꼭지점으로 하는 최대 square 의 한 변의 길이
        vector<vector<int>> table(M, vector<int>(N, 0));
        for (size_t i=0; i<M; i++) {
            for (size_t j=0; j<N; j++) {
                // 맨 위, 또는 맨 왼쪽
                if (i == 0 || j == 0) {
                    if (matrix[i][j] == '1') {
                        table[i][j] = 1;
                    }
                }
                // 그 외
                else {
                    if (matrix[i][j] == '1') {
                        table[i][j] = 1 + min({table[i-1][j], table[i-1][j-1], table[i][j-1]});
                    }
                }
                if (table[i][j] > max_len) max_len = table[i][j];
            }
        }

        return max_len * max_len;
    }
    
};
