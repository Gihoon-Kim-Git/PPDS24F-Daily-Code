#include <vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // color : curr 노드에 칠해진 색깔 (1 or 2)
        // - 0 : unvisited, not-colored
        vector<int> colors(graph.size(), 0);

        for (int source=0; source<graph.size(); source++) {
            if (colors[source] == 0) {
                if (!dfs_helper(source, 1, graph, colors)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs_helper(int curr, int color, const vector<vector<int>>& graph, vector<int>& colors) {
        colors[curr] = color;

        for (int neighbor : graph[curr]) {
            // base case : 잘못됨 감지
            if (colors[neighbor] == color) {
                return false;
            }
            // recursive case : unvisited neighbor
            else if (colors[neighbor] == 0) {
                // 3 - color : 1 -> 2 or 2 -> 1
                if (!dfs_helper(neighbor, 3 - color, graph, colors)) {
                    return false;
                }
            }
        }
        return true;
    }
};
