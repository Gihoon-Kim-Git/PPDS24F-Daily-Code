#include <vector>
using namespace std;
#include <queue>
#include <math.h>

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 0;

        int used = 0;
        vector<int> visited(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mq;
        mq.push({0,0});
        int ans = 0;
        while(used < n){
            int cost = mq.top().first;
            int v = mq.top().second;
            mq.pop();
            if(visited[v]) continue;
            ans += cost;
            visited[v] = true;
            used++;

            for(int i=0;i<n;i++){
                if(!visited[i]){
                    mq.push({abs(points[i][0]-points[v][0])+abs(points[i][1]-points[v][1]),i});
                }
            }
        }
        return ans;
    }
};