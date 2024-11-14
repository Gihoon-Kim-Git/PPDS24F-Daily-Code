class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int maxSide = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;  // Cells in the first row or column can only be 1 if they're '1'
                    } else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        
        return maxSide * maxSide;  // Area of the largest square
    }
};



// 상하좌우로 재귀 탐색 --> 이거는 연결된거 찾는 방식!!!

// class Solution {
// public:
//     bool find(vector<vector<char>>& board, int i, int j, int size, vector<vector<int>>& check, int cur) {
//         // n개가 전부 1인 경우
//         if (cur == size) {
//             return true;
//         }

//         // 범위 검사 및 이미 방문한 경우, 1이 아닌 경우 false 반환
//         if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || check[i][j] == 1 || board[i][j] != '1') {
//             return false;
//         }

//         // 현재 위치 방문 표시
//         check[i][j] = 1;

//         //1, 4, 9, 16 ... false가 나올때까지


//         bool found = find(board, i + 1, j, size, check, cur + 1) ||
//                      find(board, i - 1, j, size, check, cur + 1) ||
//                      find(board, i, j + 1, size, check, cur + 1) ||
//                      find(board, i, j - 1, size, check, cur + 1);

//         // 방문 표시 해제 (백트래킹)
//         check[i][j] = 0;
        
//         return found;
//     }



//     int maximalSquare(vector<vector<char>>& matrix) {

//         int rows = matrix.size();
//         int cols = matrix[0].size();
//         vector<vector<int>> check(rows, vector<int>(cols, 0));
//         int size=1;
//         int max=0;

//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 // '1'일 때 탐색 시작
//                 if (matrix[i][j] == '1') {
//                     while(find(matrix, i, j, pow(size, 2), check, 1)){
//                         if(size>max){
//                             cout<<i<<" "<<j<<endl;
//                             max=size;
//                         }
//                         size++;
//                     }
//                 }
//                 size=1;
//             }
//         }

//         return pow(max, 2);       
//     }
// };