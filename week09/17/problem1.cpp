// 1971. Find if Path Exists in Graph
// Easy
// Topics
// Companies
// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

// You want to determine if there is a valid path that exists from vertex source to vertex destination.

// Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 

// Example 1:


// Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
// Output: true
// Explanation: There are two paths from vertex 0 to vertex 2:
// - 0 → 1 → 2
// - 0 → 2
// Example 2:


// Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
// Output: false
// Explanation: There is no path from vertex 0 to vertex 5.
 

// Constraints:

// 1 <= n <= 2 * 105
// 0 <= edges.length <= 2 * 105
// edges[i].length == 2
// 0 <= ui, vi <= n - 1
// ui != vi
// 0 <= source, destination <= n - 1
// There are no duplicate edges.
// There are no self edges.


#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:

    // 3) union find
        
    int getParent(int x, int parent[]){
        if (parent[x] == x){
            return x;
        } else {
            return getParent(parent[x], parent);
        }   
    }

    void unionParent(int parent[], int x, int y){
        int parentX = getParent(x, parent);
        int parentY = getParent(y, parent);

        parent[parentY] = parentX;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        int parent[n];

        for (int i=0; i<n; i++){
            parent[i] = i;
        }

        for (auto e: edges){
            unionParent(parent, e[0], e[1]);
        }

        if (getParent(source, parent) == getParent(destination, parent)){
            return true;
        } else {
            return false;
        }

        // vector<vector<bool>> edgesMtx(n, vector<bool>(n, false));

        // // 일단 edges를 mtx 형태로 바꾸고 시작
        // for (auto e: edges){
        //     edgesMtx[e[0]][e[1]] = true;
        //     edgesMtx[e[1]][e[0]] = true;
        // }

        // 1) bfs -> 하나씩 queue에 넣으면서 이동
        // visited를 관리 -> visit 가능한 노드는 표시
        // queue에 노드가 없어질때까지 반복
        // visited에서 destination이 true인지 확인

        // vector<bool> isVisited(n);
        // queue<int> visitedQueue;

        // isVisited[source] = true;
        // visitedQueue.push(source);

        // while (!visitedQueue.empty()){

        //     int node = visitedQueue.front();
        //     visitedQueue.pop();

        //     for (int i=0; i<n; i++){
        //         if (edgesMtx[node][i] && !isVisited[i]){
        //             isVisited[i] = true;
        //             visitedQueue.push(i);
        //         }
        //     }
        // }

        // return isVisited[destination]; // time limit

        // 2) dfs -> 하나씩 stack에 넣으면서 이동
        // visited, stack

        // vector<bool> isVisited(n);
        // stack<int> visitedStack;

        // visitedStack.push(source);

        // while (!visitedStack.empty()){
        //     int node = visitedStack.top();
        //     visitedStack.pop();

        //     if (isVisited[node]){
        //         continue;
        //     } 

        //     isVisited[node] = true;

        //     for (int i=0; i<n; i++){
        //         if (edgesMtx[node][i]){
        //             visitedStack.push(i);
        //         }
        //     }
        // }

        // return isVisited[destination]; // time limit


    }

};