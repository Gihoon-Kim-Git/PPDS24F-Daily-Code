#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 means uncolored, 0 and 1 are the two colors

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) { // If the node is not colored
                queue<int> q;
                q.push(i);
                color[i] = 0; // Start coloring with color 0

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == -1) { // If the neighbor is not colored
                            color[neighbor] = 1 - color[node]; // Color with the opposite color
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) { // If the neighbor has the same color
                            return false; // The graph is not bipartite
                        }
                    }
                }
            }
        }

        return true; // All nodes have been colored successfully
    }
};
