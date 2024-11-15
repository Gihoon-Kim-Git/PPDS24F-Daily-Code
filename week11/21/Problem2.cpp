#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int len = cost.size();  
      vector<int> save(len+1, 0);
      if(len==2) return min(cost[0],cost[1]);
      save[0] = 0;
      save[1] = 0;
      save[2] = min(cost[0],cost[1]);
      save[3] = min(cost[1],cost[0]+cost[2]);
      if(len==3) return save[3];
      
      for(int i=4; i<len+1; i++){
            save[i]=min(cost[i-1]+save[i-1],cost[i-2]+save[i-2]);
        }
      return save[len];
    } 
};