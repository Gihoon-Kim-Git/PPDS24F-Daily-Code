#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> start;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> end;

        for (auto trip : trips){
            start.push(make_pair(trip[1], trip[0]));
            end.push(make_pair(trip[2], trip[0]));
        } 
        int m = 0;
        int n = 0;
        int curpas = 0;

        while (start.size() != 0 && end.size() != 0){
            if (start.top().first < end.top().first){
                curpas += start.top().second;
                if (curpas > capacity){
                    return false;
                }
                start.pop();
            }
            else{
                curpas -= end.top().second;
                end.pop();
            }
        }
        return true;     
    }
};