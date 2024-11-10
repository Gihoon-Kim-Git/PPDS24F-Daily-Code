// C++ BFS 구현
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void bfs(int start, const vector<vector<int>>& graph) {
    unordered_set<int> visited;
    queue<int> q;
    
    q.push(start);
    visited.insert(start);
    
    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";
        
        for(auto neighbor : graph[vertex]) {
            if(visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // 그래프 인접 리스트 표현 (1-based indexing)
    int num_vertices = 4;
    vector<vector<int>> graph(num_vertices + 1);
    
    // 간선 추가 (무방향 그래프)
    graph[1].push_back(2);
    graph[1].push_back(4);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(1);
    graph[4].push_back(3);
    
    cout << "BFS 순회: ";
    bfs(1, graph);
    cout << endl;
    
    return 0;
}