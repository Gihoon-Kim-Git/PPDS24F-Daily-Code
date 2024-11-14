#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> climbcost;
        int N = cost.size();
        
        climbcost.push_back(cost[0]);
        climbcost.push_back(cost[1]);
        if(N < 3){
            return *min_element(climbcost.begin(), climbcost.end());
        }else{
            int i = 2;
            while(N - 1 > i){
                climbcost.push_back(min(climbcost[i-1], climbcost[i-2])+cost[i]);
                i++;

            }
            
            int nn = climbcost.size();
            
            return min(climbcost[nn-1], climbcost[nn-2]+cost[N-1]);

        }
    }
};

int main(){
    Solution sol;
    vector<int> cost;
    cost.push_back(10);
    cost.push_back(15);
    cost.push_back(20);
    sol.minCostClimbingStairs(cost);
}