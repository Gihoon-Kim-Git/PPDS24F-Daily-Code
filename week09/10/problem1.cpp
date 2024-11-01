#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/* [https://leetcode.com/problems/find-if-path-exists-in-graph/description/?envType=problem-list-v2&envId=graph]
1971. Find if Path Exists in Graph

 A bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
 The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [u_i, v_i] denotes a bi-directional edge between vertex u_i and vertex v_i. 
 Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
 
 Determine if there is a valid path from vertex source to vertex destination.
 
 Return true if there is a valid path from source to destination, or false otherwise.
 
 Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.

 */
class Solution {
public:
    bool dfs(int root, int dest, vector< vector <int> >& g, vector<bool> &vis) {
        vis[root] = true;
        for (auto v: g[root]) {
            if (!vis[v])
                dfs(v, dest, g, vis);
        }
    }

    bool validPath(int n, vector<pair<int, int> >& edges, int source, int destination) {
        
        // use DFS
        //sort(edges.begin(), edges.end()); // array라면 -> sort(arr, arr+10)

        vector < vector <int> > g(n);  // 인접하는 이웃을 벡터로 갖는 2D 벡터 만들기 (양방향이라서 duplicated 하게 갖고 있음)
        for(auto v: edges) {
            g[v.first].push_back(v.second);  
            g[v.second].push_back(v.first);
        }

        vector<bool> vis(n, false);
        
        dfs(source, destination, g, vis);

        return vis[destination];


    }
    

};


int main(void) {

    int n1 = 3;
    vector<pair<int, int> > edges1;
    edges1.push_back({0,1});
    edges1.push_back({1,2});
    edges1.push_back({2,0});
    int source1 = 0;
    int destination1 = 2;   // output: true 

    int n2 = 6;
    vector<pair<int, int> > edges2;
    edges2.push_back({0,1});    
    edges2.push_back({0,2});
    edges2.push_back({3,5});
    edges2.push_back({5,4});
    edges2.push_back({4,3});
    int source2 = 0;
    int destination2 = 5; // output: false
    
    Solution sol;
    bool ans1 = sol.validPath(n1, edges1, source1, destination1);
    bool ans2 = sol.validPath(n2, edges2, source2, destination2);

    cout << "answer1 = " << ans1 << endl;
    cout << "answer2 = " << ans2 << endl;

    return 0;

}

/*
 */