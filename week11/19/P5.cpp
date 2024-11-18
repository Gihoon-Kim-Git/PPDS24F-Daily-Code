#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n_row = matrix.size();
        int n_col = matrix[0].size();

        vector<vector<int>> mtx(n_row, vector<int>(n_col, 0));

        int squareMax = 0;
        for (int i=0; i<n_row; i++) {
            for (int j=0; j<n_col; j++) {
                mtx[i][j] = matrix[i][j]-'0';
                if (mtx[i][j] == 1) {
                    squareMax = 1;
                }
            }
        }
        
        for (int i=1; i<n_row; i++) {
            for (int j=1; j<n_col; j++) {
                if (mtx[i][j] == 1) {
                    int squareMin = min({mtx[i-1][j], mtx[i][j-1], mtx[i-1][j-1]});
                    if (squareMin > 0) mtx[i][j] = squareMin + 1;
                    squareMax = max(squareMax, mtx[i][j]);
                }
            }
        }

        return squareMax * squareMax;
    }
};

int main() {
    vector<vector<char>> matrix = {{'1','1','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','1','1','1','1'}};
    Solution solution;
    int result = solution.maximalSquare(matrix);
    cout << result << endl;
    return 0;
}