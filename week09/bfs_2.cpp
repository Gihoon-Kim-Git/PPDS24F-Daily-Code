// bfs.cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // BFS 구현
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // 인접 리스트 초기화 (0-based 인덱스)
        vector<vector<int>> adj(n, vector<int>());

        // 간선 리스트를 인접 리스트로 변환
        for(int i = 0; i < edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 방문 배열 초기화
        vector<bool> visited(n, false);

        // 큐 초기화
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int current = q.front();
            q.pop();

            if(current == destination){
                return true;
            }

            // 현재 노드의 이웃 노드들 방문
            for(int i = 0; i < adj[current].size(); ++i){
                int neighbor = adj[current][i];
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};

int main(){
    Solution sol;
    int n = 3;
    vector<vector<int>> edges;
    edges.push_back(vector<int>(2, 0));
    edges[0][0] = 0;
    edges[0][1] = 1;
    edges.push_back(vector<int>(2, 0));
    edges[1][0] = 1;
    edges[1][1] = 2;
    int source = 0;
    int destination = 2;

    bool result = sol.validPath(n, edges, source, destination);
    if(result){
        cout << "경로가 존재합니다." << endl;
    }
    else{
        cout << "경로가 존재하지 않습니다." << endl;
    }

    return 0;
}