#include <vector>
#include <string>
#include <utility> // std::pair를 사용하기 위해 필요
using namespace std;
class Solution {
public:
    vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<char>> vec;
    string w;

    bool search(int x, int y, int cnt){
        if(cnt==w.size()) return true;

        if(x<0 || x>=vec.size() || y<0 || y>=vec[0].size() || vec[x][y] != w[cnt]) return false;

        char temp = vec[x][y];
        vec[x][y] = '&';

        for(auto direc : direction){
            int dx = x + direc.first;
            int dy = y + direc.second;
            if(search(dx,dy,cnt+1)) return true;
        }

        vec[x][y] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vec = board;
        w = word;
        int m = board[0].size();
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(search(i,j,0)) return true;
            }
        }
        return false;
    }
};