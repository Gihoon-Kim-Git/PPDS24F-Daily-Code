#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        int result = 0;
        // make cost vector
        vector<vector<int>> cost = {};
        for (int i=0; i<size; ++i) {
            vector<int> innerCost = {};
            for (int j=0; j<size; ++j) {
                int price = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                innerCost.push_back(price);
            }
            cost.push_back(innerCost);
        }

        vector<int> connect = {0};
        // find
        while (connect.size() < size) {
            int min_price = INT_MAX;
            int candidate;
            for (auto each : connect) {
                for (int k=0; k<size; ++k) {
                    if (each==k || find(connect.begin(), connect.end(), k) != connect.end()) {
                        continue;
                    }
                    
                    if (cost[each][k] < min_price) {
                        min_price = cost[each][k];
                        candidate = k;
                    }
                }
            }
            connect.push_back(candidate);
            result += min_price;
        }

        return result;
    }
};

int main(void) {
    Solution sol;
    vector<vector<int>> points = {{0,0}, {2,2}, {3,10}, {5,2}, {7,0}};
    int result = sol.minCostConnectPoints(points);
    cout << result << endl;
    return 1;
}