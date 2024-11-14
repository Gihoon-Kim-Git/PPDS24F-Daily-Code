#include <iostream>
#include <vector>
#include <cassert>
#include <cctype>
#include <algorithm>
using namespace std;

// 네 개의 point에서만 확인해서 틀림!!!

int maximalSquare(std::vector<std::vector<char>>& matrix){
    if (matrix.empty() || matrix[0].empty()) return 0;
    int maxSide = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // dp[i][j]는 위치 (i, j)에서 끝나는 가장 큰 정사각형의 한 변의 길이
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    
    // DP 배열을 채우면서 최대 정사각형의 한 변의 길이를 찾음
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1; // 첫 행 또는 첫 열에서 '1'인 경우
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    
    return maxSide * maxSide; // 최대 정사각형의 넓이를 반환
}

int main() {
    // 테스트 케이스 1: 일반적인 경우
    std::vector<std::vector<char>> matrix1 = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    assert(maximalSquare(matrix1) == 4);  // 2x2 정사각형

    // 테스트 케이스 2: 한 행만 있는 경우
    std::vector<std::vector<char>> matrix2 = {
        {'0', '1', '1', '1'}
    };
    assert(maximalSquare(matrix2) == 1);  // 가장 큰 정사각형은 1x1

    // 테스트 케이스 3: 한 열만 있는 경우
    std::vector<std::vector<char>> matrix3 = {
        {'1'},
        {'0'},
        {'1'},
        {'1'},
    };
    assert(maximalSquare(matrix3) == 1);  // 가장 큰 정사각형은 1x1

    // 테스트 케이스 4: 모두 1로 채워진 정사각형
    std::vector<std::vector<char>> matrix4 = {
        {'1', '1'},
        {'1', '1'}
    };
    assert(maximalSquare(matrix4) == 4);  // 2x2 정사각형

    // 테스트 케이스 5: 0이 포함된 2x2 정사각형
    std::vector<std::vector<char>> matrix5 = {
        {'1', '0'},
        {'1', '1'}
    };
    assert(maximalSquare(matrix5) == 1);  // 가장 큰 정사각형은 1x1

    // 테스트 케이스 6: 빈 행렬
    std::vector<std::vector<char>> matrix6 = {};
    assert(maximalSquare(matrix6) == 0);  // 넓이는 0

    std::cout << "모든 테스트 케이스가 통과했습니다!" << std::endl;
    return 0;
}
