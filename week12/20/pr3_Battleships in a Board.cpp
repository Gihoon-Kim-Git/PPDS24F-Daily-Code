using namespace std;
#include <vector>

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    if((i==0 || board[i-1][j] =='.') && (j==0 || board[i][j-1]=='.')) ans++;
                    // 위 or 왼쪽이 없거나 '.'이면 전함 cnt증가
                }
            }
        }
        return ans;
    }
};