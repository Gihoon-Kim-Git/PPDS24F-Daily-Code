#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // DFS 구현 (재귀적 방법)
    bool dfs(int current, int destination, vector<vector<int>>& adj, vector<bool>& visited) {
        if(current == destination) {
            return true;
        }
        visited[current] = true;
        for(int i = 0; i < adj[current].size(); ++i) {
            int neighbor = adj[current][i];
            if(!visited[neighbor]) {
                if(dfs(neighbor, destination, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    // BFS 구현 (반복적 방법, 벡터를 큐처럼 사용)
    bool bfs(int source, int destination, vector<vector<int>>& adj, vector<bool>& visited) {
        vector<int> queue;
        int front = 0;

        queue.push_back(source);
        visited[source] = true;

        while(front < queue.size()) {
            int current = queue[front];
            front++;

            if(current == destination) {
                return true;
            }

            for(int i = 0; i < adj[current].size(); ++i) {
                int neighbor = adj[current][i];
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push_back(neighbor);
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // 인접 리스트 초기화 (0-based 인덱스)
        vector<vector<int>> adj(n, vector<int>());

        // 간선 리스트를 인접 리스트로 변환
        for(int i = 0; i < edges.size(); ++i){
            if(edges[i].size() < 2){
                // 간선 데이터가 두 개의 노드를 포함하지 않으면 무시
                continue;
            }
            int u = edges[i][0];
            int v = edges[i][1];
            if(u >= n || v >= n || u < 0 || v < 0){
                // 노드 인덱스가 유효하지 않으면 무시
                continue;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // DFS를 사용하여 경로 유효성 검사
        vector<bool> visited_dfs(n, false);
        bool dfs_result = dfs(source, destination, adj, visited_dfs);

        // BFS를 사용하여 경로 유효성 검사
        vector<bool> visited_bfs(n, false);
        bool bfs_result = bfs(source, destination, adj, visited_bfs);

        // 둘 중 하나라도 경로가 유효하면 true 반환
        return dfs_result || bfs_result;
    }
};

int main(){
    Solution sol;
    
    // 예제 1
    int n1 = 3;
    vector<vector<int>> edges1;
    // 간선 추가: 0-1, 1-2
    vector<int> edge1_1;
    edge1_1.push_back(0);
    edge1_1.push_back(1);
    edges1.push_back(edge1_1);
    
    vector<int> edge1_2;
    edge1_2.push_back(1);
    edge1_2.push_back(2);
    edges1.push_back(edge1_2);
    
    int source1 = 0;
    int destination1 = 2;
    
    bool result1 = sol.validPath(n1, edges1, source1, destination1);
    if(result1){
        cout << "예제 1: 경로가 존재합니다." << endl;
    }
    else{
        cout << "예제 1: 경로가 존재하지 않습니다." << endl;
    }

    // 예제 2
    int n2 = 6;
    vector<vector<int>> edges2;
    // 간선 추가: 0-1, 0-2, 3-5, 5-4, 4-3
    vector<int> edge2_1;
    edge2_1.push_back(0);
    edge2_1.push_back(1);
    edges2.push_back(edge2_1);
    
    vector<int> edge2_2;
    edge2_2.push_back(0);
    edge2_2.push_back(2);
    edges2.push_back(edge2_2);
    
    vector<int> edge2_3;
    edge2_3.push_back(3);
    edge2_3.push_back(5);
    edges2.push_back(edge2_3);
    
    vector<int> edge2_4;
    edge2_4.push_back(5);
    edge2_4.push_back(4);
    edges2.push_back(edge2_4);
    
    vector<int> edge2_5;
    edge2_5.push_back(4);
    edge2_5.push_back(3);
    edges2.push_back(edge2_5);
    
    int source2 = 0;
    int destination2 = 5;
    
    bool result2 = sol.validPath(n2, edges2, source2, destination2);
    if(result2){
        cout << "예제 2: 경로가 존재합니다." << endl;
    }
    else{
        cout << "예제 2: 경로가 존재하지 않습니다." << endl;
    }

    return 0;
}