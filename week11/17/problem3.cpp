
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        // MST ..... ㅎㅎㅋ..

        // 일단 거리 계산
        int n = points.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dist[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            }
        }

        // prime algorithm
        // priority queue로 구현
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);
        int ans = 0;
        int cost, dest;

        // 0에서 시작
        pq.push({0, 0});
        
        // pq에서 가장 가까운거 가져와서 
        while (!pq.empty()){

            cost = pq.top().first;
            dest = pq.top().second;
            pq.pop();

            if (visited[dest]){
                continue;
            }

            // 방문
            visited[dest] = true;

            // cost 추가
            ans += cost;

            // 이웃 노드 추가
            for (int i = 0; i < n; i++){
                if (!visited[i] && dist[dest][i] != -1){
                    pq.push({dist[dest][i], i});
                }
            }

            
        }
        

        return ans;
    }
};