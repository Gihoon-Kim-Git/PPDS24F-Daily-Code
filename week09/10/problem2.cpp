#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* [https://leetcode.com/problems/is-graph-bipartite/description/?envType=problem-list-v2&envId=graph]

785. Is Graph Bipartite?
Bipartite(이분 그래프):인접한 정점끼리 서로 다른 색으로 칠해서 모든 정점을 두 가지 색으로만 칠할 수 있는 그래프.
https://gmlwjd9405.github.io/2018/08/23/algorithm-bipartite-graph.html

//////////
이분 그래프인지 확인하는 방법은 BFS, DFS 탐색을 이용하면 된다.
이분 그래프는 BFS를 할 때 같은 레벨의 정점끼리는 모조건 같은 색으로 칠해진다.
연결 성분의 개수(Connected Component)를 구하는 방법과 유사하다.
모든 정점을 방문하며 간선을 검사하기 때문에 시간 복잡도는 O(V+E)로 그래프 탐색 알고리즘과 같다.

이분 그래프인지 확인하는 방법은 너비 우선 탐색(BFS), 깊이 우선 탐색(DFS)을 이용하면 된다.

서로 인접한 정점이 같은 색이면 이분 그래프가 아니다.
BFS, DFS로 탐색하면서 정점을 방문할 때마다 두 가지 색 중 하나를 칠한다.
다음 정점을 방문하면서 자신과 인접한 정점은 자신과 다른 색으로 칠한다.
탐색을 진행할 때 자신과 인접한 정점의 색이 자신과 동일하면 이분 그래프가 아니다.
BFS의 경우 정점을 방문하다가 만약 같은 레벨에서 정점을 다른 색으로 칠해야 한다면 무조건 이분 그래프가 아니다.
모든 정점을 다 방문했는데 위와 같은 경우가 없다면 이분 그래프이다.
이때 주의할 점은 연결 그래프와 비연결 그래프를 둘 다 고려 해야한다는 것이다.
그래프가 비연결 그래프인 경우 모든 정점에 대해서 확인하는 작업이 필요하다.
///////


There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. 
You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. 
More formally, for each v in graph[u], there is an undirected edge between node u and node v. 

The graph has the following properties:
- no self-edges (graph[u] does not contain u).
- no parallel edges (graph[u] does not contain duplicate values).
- If v is in graph[u], then u is in graph[v] (the graph is undirected).
- The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
- A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

Constraints:

graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] does not contain u.
All the values of graph[u] are unique.
If graph[u] contains v, then graph[v] contains u.

*/

class Solution {
public:
    bool check(int root, vector< vector <int> > &g, vector<int> &mark) {

        // bfs
        queue<int> qu;
        mark[root] = 0;
        qu.push(root);

        while(!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            for (auto adj: g[curr]) {
                if(mark[adj]==-1) {
                    mark[curr] = !mark[curr]; // 0 -> 1, 다른 숫자(여기서는 -1)-> 0
                    qu.push(adj);
                } else if (mark[adj]==mark[curr]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> color_mark(n, -1); // red, black
            
        for (int vertex=0; vertex<n; vertex++) { 
            if (color_mark[vertex] == -1 && check(vertex, graph, color_mark))  return false;
        }
        return true;
    }
};

int main(void) {
    
    vector <vector <int> > graph1{{1,2,3},{0,2},{0,1,3},{0,2}}; // false
    vector <vector <int> > graph2{{1,3},{0,2},{1,3},{0,2}}; // true 
    
    bool ans1;
    bool ans2;

    Solution sol;

    ans1 = sol.isBipartite(graph1);
    ans2 = sol.isBipartite(graph2);

    cout << "Answer1 = " << ans1 << endl;
    cout << "Answer2 = " << ans2 << endl;

    return 0;
}