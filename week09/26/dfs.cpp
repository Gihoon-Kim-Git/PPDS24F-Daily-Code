// C++ DFS 구현
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(int vertex, unordered_set<int>& visited, const vector<vector<int> >& graph) {
    visited.insert(vertex);
    cout << vertex << " ";
    for(auto neighbor : graph[vertex]) {
        if(visited.find(neighbor) == visited.end()) {
            dfs(neighbor, visited, graph);
        }
    }
}

int main() {
    // 그래프 인접 리스트 표현 (1-based indexing)
    int num_vertices = 4;
    vector<vector<int> > graph(num_vertices + 1);
    
    // 간선 추가 (무방향 그래프)
    graph[1].push_back(2);
    graph[1].push_back(4);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(1);
    graph[4].push_back(3);
    
    unordered_set<int> visited;
    
    cout << "DFS 순회: ";
    dfs(1, visited, graph);
    cout << endl;
    
    return 0;
}