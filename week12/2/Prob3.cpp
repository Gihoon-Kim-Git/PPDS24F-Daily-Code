#include<vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == 'X'){
                    // 전함의 시작 부분인지 체크
                    if(i > 0 && board[i - 1][j] == 'X'){
                        // 위에 전함이 존재하면 이는 새로운 전함이 아님
                        continue;
                    }
                    if(j > 0 && board[i][j - 1] == 'X'){
                        // 왼쪽에 전함이 존재하면 이는 새로운 전함이 아님
                        continue;
                    }
                    // 새로운 전함으로 판단, count 증가
                    count++;
                }
            }
        }
        
        return count;
    }
};