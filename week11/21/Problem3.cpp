#include <vector>
#include <algorithm>
#include <bits/c++.h>
using namespace std;

class Solution {
public:
    int parents(int x, vector<int>& parent){
        while(x != parent[x]) x = parent[x];
        return x;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> adj;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j <n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int distance = abs(x1-x2) + abs(y1-y2);

                adj.push_back({distance, i, j});
            }
        }

        sort(adj.begin(), adj.end());
        vector<int> parent(n);

        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        int sum = 0;
        for(int i =0; i<adj.size(); i++){
            int x = adj[i][1];
            int y = adj[i][2];

            x = parents(x, parent);
            y = parents(y, parent);

            if( x != y){
                parent[y] = x;
                sum += adj[i][0];
            }
        }
    return sum;
    }
};