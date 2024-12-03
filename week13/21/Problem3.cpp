class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int len = mat.size();
        vector<pair<int, int>> ans;
        vector<int> result;


        for(int i=0; i<len ; i++){
            auto it = find(mat[i].begin(), mat[i].end(), 0);
            int temp = distance(mat[i].begin(), it);
            ans.push_back({temp, i});        
        }
        sort(ans.begin(), ans.end());

        for(int i =0; i<k; i++) {
            result.push_back(ans[i].second);
        }
        return result;
    }
};