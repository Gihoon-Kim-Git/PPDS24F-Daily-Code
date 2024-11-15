#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int Row = matrix.size();
        int Col = matrix[0].size();
        unordered_map<int, unordered_map<int, int>> cache;
        
        function<int(int, int)> help = [&](int r, int c) {
            if (r >= Row || c >= Col) return 0;
            
            if (cache.find(r) == cache.end() || cache[r].find(c) == cache[r].end()) {
                int down = help(r + 1, c);
                int right = help(r, c + 1);
                int diag = help(r + 1, c + 1);
                
                cache[r][c] = 0;
                if (matrix[r][c] == '1') {
                    cache[r][c] = 1 + min({down, right, diag});
                }
            }
            
            return cache[r][c];
        };
        
        help(0, 0);
        
        int maxSquare = 0;
        for (const auto& row : cache) {
            for (const auto& cell : row.second) {
                maxSquare = max(maxSquare, cell.second);
            }
        }
        
        return maxSquare * maxSquare;
    }
};