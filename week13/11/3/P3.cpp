#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        // 첫 번째 기준: 첫 번째 요소 기준 오름차순
        if (a.first != b.first)
            return a.first > b.first;
        // 두 번째 기준: 두 번째 요소 기준 오름차순
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for(int i = 0; i<mat.size(); i++){
            int count = 0;
            for (auto elem : mat[i]){
                if (elem == 1){
                    count++;
                }
                else{
                    break;
                }
            }
            pq.push(make_pair(count, i));
        }
        for(int j = 0; j < k;j++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};