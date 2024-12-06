class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
    bool check(int i, int j){
        if(i>=m or i<0 or j<0 or j>=n) return false;
        return true;
    }
    void solve(vector<vector<char>> &board, int row, int col){
        if(board[row][col]!='E' and board[row][col]!='M') return;

        if(board[row][col]=='M'){
            board[row][col] = 'X';
            return;
        }

        else if(board[row][col]=='E'){
            int count = 0;
            vector<vector<int>> temp;

            for(int i =0;i<8;i++){
                int new_i = dir[i][0] + row;
                int new_j = dir[i][1] + col;

                if(check(new_i,new_j)){

                    if(board[new_i][new_j]=='M'){
                        count++;
                        // solve(board, new_i,new_j);
                    }

                    else if(board[new_i][new_j]=='E'){
                        temp.push_back({new_i,new_j});
                    }
                }
            }

            if(count!=0){
                board[row][col] = char(count+'0');
            }

            else{
                board[row][col] = 'B';
                
                for(int i =0;i<temp.size();i++){
                    solve(board, temp[i][0],temp[i][1]);
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        solve(board, click[0],click[1]);
        return board;
    }
};