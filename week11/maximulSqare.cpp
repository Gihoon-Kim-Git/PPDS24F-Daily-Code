#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> mul_result = {};

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i == 0 && j == 0) { continue; }
                for (int k = 0; k < (row - i); ++k) {
                    for (int r = 0; r < (col - j); ++r) {
                        if (matrix[k][r] == '1') {
                            bool check = true;
                            for (int a = 0; a <= i && check; ++a) {
                                for (int b = 0; b <= j; ++b) {
                                    if (matrix[k + a][r + b] != '1') {
                                        check = false;
                                        break;
                                    }
                                }
                                if (!check) break;
                            }

                            if (check) {
                                mul_result.push_back((i + 1) * (j + 1));
                            }
                        }
                    }
                }
            }
        }
        
        return mul_result.empty() ? 0 : *max_element(mul_result.begin(), mul_result.end());
    }
};

int main(void) {
    Solution sol;
    vector<vector<char>> matrix =  {{'1', '0', '1', '0', '0'},
                                    {'1', '0', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1'},
                                    {'1', '0', '0', '1', '0'}};
    
    vector<vector<char>> matrix2 = {{'1', '0', '1', '0', '0'},
                                    {'1', '0', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1'},
                                    {'1', '0', '0', '1', '0'}};
    
    int result = sol.maximalSquare(matrix);
    int result2 = sol.maximalSquare(matrix2);
    cout << result << endl;
    cout << result2 << endl;
    return 0;
}


