class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int rows = board.size();
        int cols = board[0].size();
        int r = click[0], c = click[1];
        
        // Directions for 8 adjacent squares
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1},
                                             {0, -1},          {0, 1},
                                             {1, -1}, {1, 0}, {1, 1}};
        
        // Helper function to count adjacent mines
        int countMines(vector<vector<char>>& board, int r, int c) {
            int count = 0;
            for (auto& dir : directions) {
                int nr = r + dir.first, nc = c + dir.second;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'M') {
                    count++;
                }
            }
            return count;
        }
        
        // DFS function to reveal squares
        void dfs(vector<vector<char>>& board, int r, int c) {
            // Base condition
            if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'E') return;
            
            int mineCount = countMines(board, r, c);
            if (mineCount > 0) {
                board[r][c] = mineCount + '0'; // Set number of adjacent mines
            } else {
                board[r][c] = 'B'; // Set to 'B' if no adjacent mines
                for (auto& dir : directions) {
                    dfs(board, r + dir.first, c + dir.second); // Recursively reveal neighbors
                }
            }
        }
        
        // Process the initial click
        if (board[r][c] == 'M') {
            board[r][c] = 'X'; // Game over
        } else {
            dfs(board, r, c); // Start revealing
        }
        
        return board;
    }
};
