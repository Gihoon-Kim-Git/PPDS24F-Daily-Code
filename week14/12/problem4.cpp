class Solution {
public:
    //up,down, l, r,ldia,rdia,lddia,rddia
    int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
    int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
    bool validPoint(int x, int y, vector<vector<char>>& board){
        if( x<0 || y <0 || x>=board.size()||y >= board[0].size()) return false;
        return true;
    }
    int cntMine(vector<vector<char>>& board,int x, int y){
        int cnt=0;
        for(int t=0;t<8;t++){
            int i= x+dx[t];
            int j = y+dy[t];
            if(validPoint(i,j,board)&&board[i][j]=='M'){
                cnt++;
            } 
        }
        return cnt;
    }

    void dfs(vector<vector<char>>& board,int x, int y){
        if (!validPoint(x,y,board)){
            return;
        }
       
        if(board[x][y]=='M'){
            board[x][y] ='X';
            return;
        }
        
        if(board[x][y]=='E'){
            int mine= cntMine(board,x,y);
            if(mine==0){
                board[x][y]='B';
                for (int k=0; k<8; k++) {
                    dfs(board, x+dx[k], y+dy[k]);
                }
            }

            else{
                board[x][y]=mine +'0';
                return;
            }
            
            
        }
        


    }


    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];

        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        } else {
            dfs(board, x, y);
        }

        return board;
    }
};