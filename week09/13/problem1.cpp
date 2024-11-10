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

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind(n);

        for(auto i=0; i<edges.size(); i++){
            unionSets(edges[i][0], edges[i][1]);
        }

        return find(source)==find(destination);
    }

};

// 초기화:

// 각 노드는 자기 자신을 부모로 가집니다 (parent[i] = i).
// rank 배열을 사용해 트리의 깊이를 추적하고, 합치는 과정에서 깊이가 더 작은 트리를 큰 트리에 붙여 최적화를 수행합니다.
// Find 연산:

// find 함수는 노드 x의 루트(parent)를 찾습니다.
// 경로 압축을 통해 중간 노드들이 루트에 직접 연결되도록 하여, 다음 find 연산이 더 빠르게 이루어지도록 합니다.
// Union 연산:

// unionSets 함수는 두 노드 x와 y를 같은 집합으로 합칩니다.
// 두 노드의 루트를 찾고, rank에 따라 트리를 연결합니다. 깊이가 작은 트리를 깊이가 큰 트리에 붙여 불필요한 트리 깊이를 방지합니다.
// isConnected:

// 두 노드가 같은 집합에 속해 있는지 확인할 때 사용합니다. 두 노드의 루트가 같으면 같은 집합에 속해 있다고 판별합니다.



//map:키-값으로 저장, red-black tree기반 <> unordered_map: 해시테이블 기반으로 구현
//map은 기본적으로 일대일, 하나의 키에 하나의 값이 저장됨 -> 하나의 키에 여러개의 값을 저장하려면 vector<int>를 집어넣는 방법이 있음
//unordered_map<int, vector<int>>
// .first와 .second로 관리함
// .find(key) != .end() 로 key가 존재하는지를 확인할 수 있음


//map 삽입/삭제/검색이 O(log n)
//unordered_map 삽입/삭제/검색이 O(1)
//삽입-검색이 빠르고, 데이터의 순서가 중요하지 않을 때 주로 사용
