class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        int ans=0;
        for (int i=0; i < board.size(); i++) {
            for (int j=0; j < board[0].size(); j++) {
                if (!visited[i][j] && (board[i][j] == 'X')) {
                    dfs(i, j, visited, board);
                    ans += 1;
                }
            }
        }
        return ans;
    }

    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& board) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return;
        if (visited[row][col] || board[row][col] != 'X') {
            return ;
        }
        visited[row][col] = true;

        vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        for (int i=0; i < directions.size(); i++) {
            int nr = row + directions[i].first;
            int nc = col + directions[i].second;
                dfs(nr, nc, visited, board);
            }
        }
    };
