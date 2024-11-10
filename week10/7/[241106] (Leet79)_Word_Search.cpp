#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, const string& word, vector<vector<bool>>& visited){
    if (word.empty()) {
        return true;
    }
    
    int rows = board.size();
    int cols = board[0].size();

    if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] == true || board[i][j] != word[0]){
        return false; //왜 word[0]이지 >>  이해
    }

    visited[i][j] = true;

    //const string word_sub = strcpy(word, 1, word.size()-1); 이거는 C스타일 방식이라고 함.
    const string word_sub = string(word.begin()+1, word.end());
    bool result = dfs(board, i-1, j, word_sub, visited) || dfs(board, i+1, j, word_sub, visited) || dfs(board, i, j-1, word_sub, visited)|| dfs(board, i, j+1, word_sub, visited) ;

    visited[i][j] = false;

    return result;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows;++i){
            for (int j = 0; j < cols; ++j){
                if (dfs(board, i, j, word, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};