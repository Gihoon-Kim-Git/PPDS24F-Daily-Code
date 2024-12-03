#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> strength;
        for (int i = 0; i < mat.size(); ++i) {
            int count = countSoldiers(mat[i]);
            strength.emplace_back(count, i);
        }
        sort(strength.begin(), strength.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(strength[i].second);
        }
        return result;
    }

    int countSoldiers(const vector<int>& row) {
        return upper_bound(row.begin(), row.end(), 1, greater<int>()) - row.begin();
    }
};