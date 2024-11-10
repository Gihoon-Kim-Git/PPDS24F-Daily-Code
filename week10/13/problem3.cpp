class Solution {
public:
    bool find(vector<vector<char>>& board, int i, int j, string& word, vector<vector<int>>& check, int cur) {
        // 단어를 완성한 경우
        if (cur == word.size()) {
            return true;
        }

        // 범위 검사 및 이미 방문한 경우, 문자 불일치 시 false 반환
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || check[i][j] == 1 || board[i][j] != word[cur]) {
            return false;
        }

        // 현재 위치 방문 표시
        check[i][j] = 1;

        // 상하좌우로 재귀 탐색
        bool found = find(board, i + 1, j, word, check, cur + 1) ||
                     find(board, i - 1, j, word, check, cur + 1) ||
                     find(board, i, j + 1, word, check, cur + 1) ||
                     find(board, i, j - 1, word, check, cur + 1);

        // 방문 표시 해제 (백트래킹)
        check[i][j] = 0;
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;

        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> check(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // 첫 글자가 일치할 때 탐색 시작
                if (board[i][j] == word[0] && find(board, i, j, word, check, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
