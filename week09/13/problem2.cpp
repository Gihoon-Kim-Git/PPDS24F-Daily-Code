class Solution {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:

    // 초기화: 각 노드를 자기 자신을 부모로, 랭크는 0으로 설정
    void UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find 연산 (경로 압축을 사용하여 최적화)
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // 경로 압축
        }
        return parent[x];
    }

    // Union 연산 (랭크를 사용하여 최적화)
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // 랭크를 비교하여 더 작은 트리를 큰 트리에 연결
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }


    bool isBipartite(vector<vector<int>>& graph) {

        UnionFind(graph.size());

        for (int i = 0; i < graph.size(); ++i) {
            for (int neighbor : graph[i]) {
                // 현재 노드와 이웃 노드가 같은 집합에 속해 있다면 이분 그래프가 아님
                if (find(i) == find(neighbor)) {
                    return false;
                }
                
                // 이웃 노드끼리 같은 집합으로 합치기
                unionSets(graph[i][0], neighbor);
            }
        }
        
        return true;
    }

};