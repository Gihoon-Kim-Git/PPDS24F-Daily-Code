#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool search(int i, int j, int n, int m, vector<vector<char>>& board, int k, string word){
        if(k == word.size()) return true;
        if(i==n || i<0 || j<0 || j ==m || board[i][j] != word[k]) return false;

        char letter = board[i][j];
        board[i][j] = '!';

        bool up = search(i-1, j, n,m, board, k+1, word);
        bool down = search(i+1, j, n,m, board, k+1, word);
        bool left = search(i, j-1, n,m, board, k+1, word);
        bool right = search(i, j+1, n,m, board, k+1, word);
    
        board[i][j] = letter;
        
        return up||down||left||right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(search(i,j,n,m,board,0,word)) return true;
            }
        }
    return false;    
    }
};