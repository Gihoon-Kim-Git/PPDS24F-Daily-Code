class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt=0;
        for(auto i=0; i<board.size(); i++){
            for(auto j=0; j<board[0].size(); j++){
                if(board[i][j]=='X'){
                    cnt++;
                    if(j+1<board[0].size() && board[i][j+1]=='X') //가로로 생긴 배
                    {
                        int b=j+1;
                        while(b<board[0].size() && board[i][b]=='X'){
                            board[i][b]='.';
                            b++;
                        }
                    }
                    else if(i+1<board.size() && board[i+1][j]=='X'){ //세로로 생긴 배
                        int a=i+1;
                        while(a<board.size() && board[a][j]=='X'){
                            board[a][j]='.';
                            a++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};