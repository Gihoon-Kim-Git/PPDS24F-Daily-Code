class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> m;
        vector<int> ans;
        for (int i=0; i < mat.size(); i++) {
            m.push({accumulate(mat[i].begin(), mat[i].end(), 0), i});
        }

        for (int i=0; i < k; i++) {
            ans.push_back(m.top().second);
            m.pop();
        }
        return ans;
    }
};