class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

        int n = mat.size();
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int it : mat[i]) {
                if (it == 1) {
                    cnt++;
                }
            }
            pq.push(make_pair(cnt, i));
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};