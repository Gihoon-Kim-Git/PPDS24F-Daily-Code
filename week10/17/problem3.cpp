// 79. Word Search
// Medium
// Topics
// Companies
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.



// dfs로 풀어보자


#include <iostream> 
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0]){
                    if (dfs(board, word, i, j, visited, 1)){
                        return true;
                    }
                }
            }
        }

        return false;
        
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j, vector<vector<bool>>& visited, int idx){

        // board[i][j] == word[idx]인 경우, 해당 neighbor에 대해 dfs를 수행
        // neighbor 중에서 word[idx+1]과 같은 경우에 대해

        if (idx == word.size()){
            return true;
        }

        visited[i][j] = true;

        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int k = 0; k < 4; k++){
            int dx = directions[k][0];
            int dy = directions[k][1];

            if ( 0 <= i + dx && i + dx < board.size() && 0 <= j + dy && j + dy < board[0].size() && !visited[i+dx][j+dy] && board[i+dx][j+dy] == word[idx]){
                if (dfs(board, word, i+dx, j+dy, visited, idx+1)){
                    return true;
                }
            }

        }

        visited[i][j] = false;

        return false;
    }
};