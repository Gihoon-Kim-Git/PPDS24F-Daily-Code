class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n);

        for (int i = 0; i < n; i++) {
            if (colors[i]) continue;
            queue<int> q{{i}};
            colors[i] = 1;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int neighbor : graph[curr]) {
                    if (colors[neighbor] == colors[curr]) return false;
                    if (colors[neighbor] == 0) {
                        colors[neighbor] = -colors[curr];
                        q.push(neighbor);
                    }
                }
            }
        }
        return true;
    }
};