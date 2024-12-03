#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        // priority_queue를 min heap으로 사용하는 방법
        
        for (int i = 0; i < mat.size(); i++) {
            int soldier = 0;
            while (soldier < mat[i].size() && mat[i][soldier] == 1) soldier++;
            Q.push(make_pair(soldier, i));
        }
        vector<int> res;        
        for (int i = 0; i < k; i++) {             
            res.push_back(Q.top().second);
            Q.pop();
        }
        return res;
    }
};