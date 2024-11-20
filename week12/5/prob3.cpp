#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int numIslands = 0;
        unordered_map<int, vector<int>> adj = convertGridToAdj(board);
        unordered_map<int, bool> visited;
        for(const auto& pair : adj) {
            visited[pair.first] = false;
        }
        for(const auto& pair : adj) {
            if (!visited[pair.first]) {
                dfs_from_source(pair.first, adj, visited);
                numIslands += 1;
            }
        }
        
        return numIslands;
    }

    unordered_map<int, vector<int>> convertGridToAdj(vector<vector<char>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<int>> directions = {
                        {-1, 0},
                {0, -1},        {0, 1},
                        { 1, 0}
        };

        unordered_map<int, vector<int>> adj;
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                if (grid[i][j] == 'X') {
                    int curr = i * N + j;
                    adj[curr] = {};
                    for (vector<int> d : directions) {
                        int ii = i + d[0];
                        int jj = j + d[1];
                        if (ii>=0 && ii<M && jj>=0 && jj<N && grid[ii][jj] == 'X') {
                            int neighbor = ii * N + jj;
                            adj[curr].push_back(neighbor);
                        }
                    }
                }
            }
        }
        return adj;
    }

    void dfs_from_source(int source, unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& visited) {
        visited[source] = true;
        for (int neighbor : adj[source]) {
            if(!visited[neighbor]) {
                dfs_from_source(neighbor, adj, visited);
            }
        }
    }
};
