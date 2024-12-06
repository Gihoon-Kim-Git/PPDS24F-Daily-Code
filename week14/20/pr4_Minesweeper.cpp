#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> direction = {{0,1},{0,-1},{1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1}};

    int mine(vector<vector<char>>& board,int& x, int& y, int& m, int& n){
        int cnt = 0;
        for(const auto pair : direction){
            int a = pair[0];
            int b = pair[1];
            int dy = y+a;
            int dx = x+b;
            if(0<=dx && dx<n && 0<=dy && dy<m && board[dy][dx] == 'M') cnt++;
        }
        return cnt;
    }

    void dfs(vector<vector<char>>& board,int x, int y, int m, int n){
        if(!(0<=x && x<n && 0<=y && y<m && board[y][x] == 'E')) return;

        int cnt = mine(board,x,y,m,n);
        if(cnt>0){
            board[y][x] = cnt+'0'; // cnt>0의 경우 주변 친구들을 탐색하여 dfs recursive쓰지 않음
        }
        else{
            board[y][x] = 'B';
            for(auto &pair : direction){
                dfs(board,x+pair[0],y+pair[1],m,n);
            }
        }

    }    

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int y = click[0];
        int x = click[1];
        if(board[y][x]=='M'){
            board[y][x] = 'X';
            return board;
        }
        dfs(board,x,y,board.size(),board[0].size());
        return board;
    }
};